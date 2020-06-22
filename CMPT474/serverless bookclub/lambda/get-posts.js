// Query and Scan Data with AWS SDK for JavaScript in DynamoDB
// https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/GettingStarted.NodeJs.04.html

const AWS = require('aws-sdk');

const ddb = new AWS.DynamoDB.DocumentClient();

const POSTS_TABLE_NAME = "posts";

exports.handler = (event, context, callback) => {
    if (!event.requestContext.authorizer) {
      errorResponse('Authorization not configured', context.awsRequestId, callback);
      return;
    }

		const requestBody = JSON.parse(event.body);

		var since = parseInt(requestBody.since)

		var params = {
		    TableName : POSTS_TABLE_NAME,
				ExpressionAttributeNames: {"#ts": "timestamp"},
				ExpressionAttributeValues: {":since": since},
				FilterExpression: "#ts > :since",
		};

		ddb.scan(params, function(err, data) {
		    if (err) {
					callback(null, {
						statusCode: 500,
						body: JSON.stringify({Error: err}),
						headers: {'Access-Control-Allow-Origin': '*'},
					});
		    } else {
					callback(null, {
	            statusCode: 200,
	            body: JSON.stringify({results: data.Items}),
	            headers: {'Access-Control-Allow-Origin': '*'},
	        });
		    }
		});
};
