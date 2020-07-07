from kafka import KafkaConsumer
 
consumer = KafkaConsumer('sex')
for msg in consumer:
    print((msg.value).decode('utf8'))
