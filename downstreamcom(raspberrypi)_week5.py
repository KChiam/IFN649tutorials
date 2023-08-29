import paho.mqtt.client as mqtt
import serial # importa serial lib!

# Function for connecting RP to AWS for MQTT to do its thing. Verify connection to topic through MQTT > subscribe to topic > verify what topic you're subscribing to
def on_connect(client, userdata, flags, rc):
	print("Connected to MQTT Server {ADD} at port {PORT}")
	print("Connection returned result: " +str(rc))
	topic = "ifn649"
	client.subscribe(topic)
	print("Subscribed to topic: {topic}")

# TWO MESSENGERS ARE DOING ITS JOB HERE: MQTT postwoman (AWS - RP) and BT postwoman (RP - Teensy) 
# 1. MQTT: Function for receiving message from AWS to RP via MQTT postwoman. Verify a message was received > Show what the message is > tell the world whatchu doing 
# 2. BT: At the background - send the message from RP to Teensy via BT postwoman 
def on_message(client, userdata, msg):
	print("Received message!")
	print(msg.topic+" "+str(msg.payload))
	print("relaying to teensy over BT...")
	# Code from last week's bt.py
	# relay the command from Pi to Teensy
	# Connect Pi with Teensy over BT first!
	ser = serial.Serial("/dev/rfcomm0",9600)
	ser.write(msg.payload)

ADD = "52.64.82.226"
PORT = 1883

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect(ADD, PORT, 60)
client.loop_forever()