const AWS = require('aws-sdk');

const ddb = new AWS.DynamoDB.DocumentClient();

const POSTS_TABLE_NAME = "posts";

exports.handler = (event, context, callback) => {
    if (!event.requestContext.authorizer) {
      errorResponse('Authorization not configured', context.awsRequestId, callback);
      return;
    }

    const requestBody = JSON.parse(event.body);

		// This will get inserted in the table
		item = {
			id: Math.floor(Math.random() * 100000000000),
			timestamp: Date.now(),
			username: event.requestContext.authorizer.claims['cognito:username'],
			title: requestBody.title,
			text: requestBody.text
		};

    ddbput(POSTS_TABLE_NAME, item).then(() => {
        callback(null, {
            statusCode: 201,
            body: JSON.stringify({
                timestamp: item.timestamp
            }),
            headers: {
                'Access-Control-Allow-Origin': '*',
            }
        });
    }).catch((err) => {
        console.error(err);
        errorResponse(err.message, context.awsRequestId, callback)
    });
};

// Generic DynamoDB put-item function
function ddbput(table_name, item) {
    return ddb.put({
        TableName: table_name,
        Item: item
    }).promise();
}

function errorResponse(errorMessage, awsRequestId, callback) {
  callback(null, {
    statusCode: 500,
    body: JSON.stringify({
      Error: errorMessage,
      Reference: awsRequestId,
    }),
    headers: {
      'Access-Control-Allow-Origin': '*',
    },
  });
}
