import boto3
import json
import uuid

def lambda_handler(event, context):
    dynamodb = boto3.resource('dynamodb', region_name='us-east-1', endpoint_url="https://dynamodb.us-east-1.amazonaws.com")
    table = dynamodb.Table('ContactUs')

    messageid = str(uuid.uuid4())
    email = event['email']
    subject = event['subject']
    body = event['body']

    body = table.put_item(
        Item = {
                'MessageId': messageid,
                'email': email,
                'subject': subject,
                'body': body
            }
        )

    response = {
        'statusCode': 200,
        'Access-Control-Allow-Origin': '*',
        'body': body
    }
    return json.dumps(response)
