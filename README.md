# Sound


Wiki
--------------------------------------------------
<p align="center">
  <img src="http://www.hu.nl/static/images/share.png" width="30%" height="30%">
</p>
<br>
<p align="center">Hogeschool Utrecht</p>
<p align="center">R2D2 2019</p>
<p align="center">2018_TCTI-R2D2-17_3_V</p>


***

<p align="center"><b>Sound Research Document</b></p>

***

<p align="center">
  <b><i>Authors:</i></b><br>
  - Youri Mulder<br>
  - Olivier Verwoerd
</p>

## Description module
-----

The sound module is responsible for playing sounds. The module should be able to play some sort of file like mp3 or somthing as simple as to output a frequency. 

## User storys
-----
* As a Developer I want to know what the robot is doing and if it needs somthing (Battery low).
* As a User I want to be informed on helpful information

## Input


## Output
-----
* A Frequency for a sertain time
* An input for an external driver 



## Why is this module relevant?
-----

During a rescue operation it is important to be able to communicate with humans.
We want to give it's surrounding awarness whithout the need of reading in an emergancy situation

## Research
-----
**Broad initial research** <br>
By Youri Mulder

The sound input is very output dependent.
If the ouput is only a high or low pitch with a duration the input will be the pitch and the duration.
Is the output a song/voice the input should be a file or some kind of data which contains the song data.

### Pitch
Using a piezzo buzzer a bot could be able to play a basic sound based on a pitch and duration. Creating a tone could be done using PWM or any other way to turn set a pin low and high quickly. Using this pitch you can create basic recognizable sound patterns.

You could for example take a look at RTTTL thisis a Ring Tone Text Transfer Language used to create ringtones of old Nokia phones.
A RTTTL file looks like this: 
`HauntHouse: d=4,o=5,b=108: 2a4, 2e, 2d#, 2b4, 2a4, 2c, 2d, 2a#4, 2e., e, 1f4, 1a4, 1d#, 2e., d, 2c., b4, 1a4, 1p, 2a4, 2e, 2d#, 2b4, 2a4, 2c, 2d, 2a#4, 2e., e, 1f4, 1a4, 1d#, 2e., d, 2c., b4, 1a4`
http://merwin.bespin.org/t4a/specs/nokia_rtttl.txt 

This file format is very small and easy to use. I would recommend using this over a different audio format, because this cost way less memory than other options.

http://www.nomad.ee/micros/rtttl.shtml <br>
Many implemtation can be found to ouput these RTTTL files.

### Audio file
https://www.arduino.cc/en/Tutorial/SimpleAudioPlayer

### Compressed
---
***Lossy*** <br>
Lossy compression mean the compressed file is **NOT** able to return to it's original state. Some data will be lost in the compresion. That's why lossy compressed audio files contain lower quality audio. For example the AAC file format uses a algorithm that detects frequencies that a human shouldn't be able to hear and removes these. 
Because these files contain less data the sizes will be smaller. This could be an advantage when you don't have much room but still want to be able to play a song or voice.
A lossy compressed MP3 audio file consumes 4-5MB of space while a lossless compressed WAV takes 30MB. This is close to 6 times larger.
https://www.lifewire.com/what-makes-an-audio-format-lossy-2438561 
An well known example of a lossy compressed audio file is MP3. The file format MP3 is one of the most popular/used lossy audio formats on the world. 

---

***Lossless*** <br>
Lossless compression means the compressed file is able to return to it’s original state using decompression. Different file types have different compression ratios, this is the difference in size between the original file and the compressed file.

Figure 1 http://fmedia.firmdev.com/audio-formats/ <br>
As you can see in the figure 1 the compression ratio of a WAVE is 100.0%, this means the file is uncompressed. 
FLAC is a open-source lossless audio codec. That’s why it’s great for software developers. The downside of FLAC is that the files are very big compared to lossy compressed audio files such as mp3. 
https://www.tomsguide.com/us/what-are-audio-codecs,review-4469.html

---

### File sizes
http://fmedia.firmdev.com/audio-formats/

<details>
Source file: A classic symphony by Vivaldi

| Filetype    | Settings 	| Bytes  	| Decoding sec 	| Encoding sec 	|
| :---:         |:---:          | :---:         | :---:         | :---:         | 
| WAVE      	| Audio CD 	| 56024684 	| 0	        | 0		|
| FLAC      	| q6      	| 29916278 	| 0.41		| 1.2		|
| WavPack 	| "normal"      | 29808098 	| 1.2		| -		|
| APE 		| "normal"      | 29094944 	| 2.89		| -		|
| OptimFROG 	| preset=2      | 27222439 	| 5		| 8.56		|
| Vorbis 	| q7.0      	| 8018413 	| 1.04		| 5.53		|
| Opus 		| br=192      	| 7672907 	| 1.61		| 6.16		|
| MPEG-1 	| V2      	| 7394749 	| 0.57		| 5.75		|
| AAC LC 	| br=224      	| 8952339 	| 1.62		| 7.85		|

</details>

--- 
### On bot sound
The audio input depends on what you want to archieve. In most cases a simple high/low pitch for a given duration will be enough. <br>
Some cases might require other audio ouput like a voice to give instructions to humans. This requires other input.
### Pitch
Like I've told before a simple pitch could be archieved by a piezzo buzzer. You can also think of a air raid as a sufficient audio ouput. The adventage of a air raid is the amount of decibels it's able to create.

### Voice
When you want to output a simple voice you need to store it somewhere on the bot. Most bots don't have enough internal memory to store these audio files. Take 

### Final decision
https://trello.com/c/b5lEgvUF/72-brandon-kroes asked us what the input of our module will be. Brandon is looking for the best way to store recorded samples using the https://trello.com/c/gWzkgR5t/164-microphone. Our input should support the recorded samples of the https://trello.com/c/gWzkgR5t/164-microphone. So we will wait for further information about the way they'll store their data.

We chose to start prototyping using a mp3 module which we had in stock because the product owner wanted to see quick results as fast as possible to keep the costs low. 

<br><br><br>
<br><br><br>
### Prototype mp3 player
Sound research
By Olivier Verwoerd




The mp3 player in stock
Dynamics
Advice


Main question
What is the best way to communicate with surrounding humans to inform them with as minimal hardware and expenses as possible.

Theoretical Framework:
Scope research: R2D2 2019 swarm robotics
Humans: Anyone with or without knowledge of the project.
Minimal hardware: As less hardware without compromising the functionality of the desired product.
Sub questions
How loud should the device be?
What sound output is desired?
What hardware can be used


How loud should the device be?
What sound output is desired?
The sound we produce is to inform the surrounding humans. But what do we want to inform them of? When you get out of your car and you hear a simple beeping, we know that the lights are still on. We get information from our surroundings that isn’t always spoken text. If someone is starting to drive, that someone will not know what the beeping means. That someone will understand that something is wrong and that the car is trying to tell something. If you get a notification on your phone, you check your phone and see what is going on. We can tell the difference between a call and a message. In general we use the screen to get our information. There are usecases where a voice is not   We want our product to be clear as can desired. Maybe some of the swarm robots have a different function and fine with just a battery low beep. 





Beeps
Tones
Sound
Warn
x
x
x
Inform know users


x
x
Inform everyone




x


The mp3 player in stock
The product owner demanded direct results. Because of this we used a mp3 player we had in stock. 

This particular module has no pin support for arduino. So the board was measured for input. 
The buttons work by a pulldown, meaning if the voltage from 3.3v drops to 0. The button is pressed. The way to trigger this is by connecting the grounds and connect the button pin to an open collector pin on on the arduino.

Dynamics
When the board is connected to power and playable file can be found on the USB or SD card, the board will directly start playing. This is not preferred. The rest of the settings have a memory function so here’s a list of dynamics
Autostart when powered on
Volume is always set to 50% after restart
It remembers what track it was playing last and start from the beginning of that track
There is no way to tell when a songs over (The reason why there is no song select)
Volume 60 makes the loudest noise without any distortion
Volume up is triggered by next and back button at the same time

These are not the ideal functions for this scope. We don’t want to play a track of battery low instead of is somebody stuck in a fire?

DFplayer

The DFPlayer Mini MP3 Player For Arduino is a small and low price MP3 module with an simplified output directly to the speaker. The module can be used as a stand alone module with attached battery, speaker and push buttons or used in combination with any other with RX/TX capabilities (Source: www.dfrobot.com).



This board has an extended interface over the other board we had in stock but loses the amplifier. With this module sound can be controlled and be use to send the right message at the right time. 

The development will be based of an arduino library made by the manufacturer (Source: DFrobot github).This will have to be changed to the library to work with hwlib but there’s no need for a research in what the device can do and how to interact with it. (full chipset documentation)

Arduino DUE
Buzzer
The arduino can be used to power a buzzer. This is not much harder than to set the output of a pin to high. This can only beep on one frequency but is the most simple and cost effect way to warn its surroundings.
Inteval on / off
We could also use a speaker (with amplifier) to set 
PWM Chip
The arduino DUE as a Pulse-width modulation chip that can handle 8 channels. Meaning that the board is not using any processing power during the use of the chip as long as there isn’t more than 8 different frequencies used. To make it a bit more complicated is that the pins on the board that are marked PWM are not PWM at all.  

The following pins can be used where the H is standard high and L low. The number behind H or L is the channel number. The rest indicates the pin how it’s marked on the board (Source: Old code of Stein Bout & Olivier Verwoerd):


### Supported pinout
<details>

| Channel | Ports                                               |
|---------|-----------------------------------------------------|
| PWM_CH0 | H0_RX0, H0_SDA, H0_D35, L0_LEDTX, L0_DAC1, L0_D34   |
| PWM_CH1 | H1_D42, H1_SCL, H1_D37, L1_RX2, L1_A8, L1_D36       |
| PWM_CH2 | H2_TX2, H2_D53, H2_D39, L2_D43, L2_A9, L2_D38       |
| PWM_CH3 | H3_TX0, H3_DAC0, H3_D41, L3_CANTX0, L3_PB19, L3_D40 |
| PWM_CH4 | H4_PC20 (No Physical pinout), L4_D9                 |
| PWM_CH5 | H5_D44, L5_D8                                       |
| PWM_CH6 | H6_D45, L6_D7                                       |
| PWM_CH7 | L7_D6                                               |

</details>



# Advice
I would advice better hardware for a part of the devices that have to actively interact with surroundings to help. A DFPlayer seems to be the best option since it was designed for spoken messages for information and to be combined with external hardware such as an arduino. 

https://nl.aliexpress.com/item/LEORY-DFPlayer-Mini-MP3-Speler-Module-voor-Arduino-24-bit-DAC-Output-Voice-Module-Ondersteuning-MP3/32849088916.html?albbt=Google_7_shopping&isdl=y&slnk=&albslr=226267550&src=google&acnt=494-037-6276&aff_platform=google&crea=nl32849088916&netw=u&plac=&albcp=1706100219&mtctp=&aff_short_key=UneMJZVf&gclid=CjwKCAiA_P3jBRAqEiwAZyWWaMl7cMt-1bQvWsR3hhOt3h3fiTQzWkYU8iNePNwRfwBRENVCC0M0mhoCJ6kQAvD_BwE&albag=73428776544&albch=shopping&albagn=888888&trgt=296904914040&device=c&gclsrc=aw.ds

But since this might come in late for this project. I suggest to buy from a dutch store for a bit more like here: https://www.hobbyelectronica.nl/product/mini-mp3-player-module/


For the rest of the devices that do not require actively helping humans. A tone would be advised from the output of the arduino pwm chip.

The module will in both scenarios be very quiet. An extra amplifier is probably needed.
