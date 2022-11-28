import requests
import json

url = 'https://fullnode.devnet.sui.io:443'

payload = json.dumps({
  'jsonrpc': '2.0',
  'id': 1,
  'method': 'sui_getTransactions',
  'params': [
    'All'
  ]
})
headers = {
  'Content-Type': 'application/json'
}

response = requests.request('POST', url, headers=headers, data=payload)

data = json.loads(response.text)['result']['data']

with open('./tx-list.csv', 'w') as f:
  f.write(','.join(data))

