# Smoke detector

Have you ever burned out your house because you forgot that you had a bonfire in the kitchen?
No?
Oh, luckily, nether I.
But there's a project to create a smoke detector, because prevention is better than cure! 

# So, how can I create my own smoke detector?

In tis repository you'll find:
- Arduino source, where you can find:
   - Old circuit: it contains the photo and the code of an easy circuit, you'll need an Arduino (or something similar) board, a smoke detector, two leds, a buzzer (passive, I think), three resistors (220 ohm). It is an older version of the circuit, but it doesn't matter.
   - New circuit: new version of the circuit, with lcd and three led. It is powerful than older version.  
   There's one sketch, SerialeArduino, is only a stupid sketch to print random numbers (not so random, I was in a hurry and I haven't inizializated nothing, so it will print the same old numbers every time), it could be useful if you haven't got a smoke detector yet. 
	We'll add NewCircuit.io soon. 
- C source: you have to use different code if you're on Windows or on Unix, so choose the directory you need

# Unix World
There are two different files but you need only the second one.
The first one, named dweet, sends data to dweet.io, as you can read above. It isn't the 
best part of the work, I think.
Second one communicates with firebase, so we can read all the data with an app done using
app inventor 2. 

# Windows
(Are you reeeally sure you want to use Windows? :c)
- dweet: an example, with this you can send your data on dweet.io
- Grafico: work in progress
- SerialeC: reads all the data on serial port and sends on dweet 

# How does it work?
There are two version of the circuit:
- Old version -> if there's gas in the air, the buzzer rings and the red led switches on. Otherwise, the red led and the buzzer are off and the green led is on.
- New version -> there are three led, green, yellow and red, they mena "it's ok", "warning" and "gas presence". There is a LCD that shows gas sensor value. 