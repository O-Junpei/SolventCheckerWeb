import json

path = open('log.json' , 'r') 
json_dict = json.load(path) #ここが(2)

#read json
for dict in json_dict:
  print(dict)

from datetime import datetime
now_time = datetime.now()

#write
add_dict = {}
add_dict['data'] = '5.6'
add_dict['year'] = now_time.year
add_dict['month'] = now_time.month
add_dict['day'] = now_time.day
add_dict['hour'] = now_time.hour
add_dict['minute'] = '5.6'
add_dict['second'] = '5.6'

print(add_dict)
