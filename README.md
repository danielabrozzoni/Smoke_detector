# Smoke detector

Have you ever burned out your house because you forgot that you had a bonfire in the kitchen?
No?
Oh, luckily, nether I.
But there's a project to create a smoke detector, because prevention is better than cure! 

# So, how can I create my own smoke detector?

In tis repository you'll find:
- circuit1.png: an easy circuit, you'll need an Arduino (or something similar) board, a smoke detector, two leds, a buzzer (passive, I think), three resistors (220 ohm)
- Arduino source: there are two sketch, the first one is Sensoreconbuzzer, that contains the real code. The second one, SerialeArduino, is only a stupid sketch to print random numbers (not so random, I was in a hurry and I haven't inizializated nothing, so it will print the same old numbers every time), it could be useful if you haven't got a smoke detector yet. 
- C source: you have to use different code if you're on Windows or on Unix

# Unix World
You have only one file, it isn't difficult lol
# Windows
(Are you reeeally sure you want to use Windows? :c)
- dweet: an example, with this you can send your data on dweet.io
- Grafico: in progress
- SerialeC: reads all the data on serial port and sends on dweet 

# How does it work?
I'm a mathematician, not an engineer, so I don't know deeply how circuit works. 
I only know that there are two led and a buzzer: if your sensor sends a data that is equal or greater than a threshold value, red led will be on and buzzer will ring. 
All the data will be shown on the screen (if we write the part to draw the graphic, I think) and will send to dweet.io
You can see a real time graphic online using freeboard.io, that comunicates with dweet.io 
