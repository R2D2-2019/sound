SEARCH             += ../../../libraries/USART_library/code/headers
SEARCH             += ../../../libraries/datastructures/code/headers
USART             ?= ../../../libraries/USART_library
include           $(USART)/Makefile.inc
DATA              ?= ../../../libraries/datastructures
include           $(USART)/Makefile.inc


<p align="center">Hogeschool Utrecht</p>
<p align="center">
  <img src="http://www.hu.nl/static/images/share.png" width="30%" height="30%">
</p>
<br>
<p align="center">R2D2</p>
<p align="center">2018_TCTI-R2D2-17_3_V</p>


***

<p align="center"><b>Robot Arm Research Document</b></p>

***

<p align="center">
  <b><i>Authors:</i></b><br>
  - Rik <i>Honcoop</i> <br>
  - Tim van <i>Dijk</i><br>
  - Jasper de <i>Winther</i><br>
  - Renske <i>Kuip</i><br>
  - Marc <i>Dirven</i><br>
</p>

<br>


> ‘‘Which robotic arm has the most favorable strength / lightness ratio, so that it can participate in as many emergency areas as possible in comparison with other robotic arms, while remaining affordable?’’

<br><br><br><br>

## Abstract
This research paper is about which robot arm has the most favorable strength/lightness ratio, so that it can be applied to Swarm Robotics, with as main question: 
> ‘‘Which robotic arm has the most favorable strength / lightness ratio, so that it can participate in as many emergency areas as possible in comparison with other robotic arms, while remaining affordable?’’.

The applied research method is “Triangulation Framework”, which is commonly used in the Information and Communication Technology sector.
<br>
According to how much money we have to spend, different robotic arms can be advised. The robotic arm with the most common grounds is ... and costs ...

TODO:
In dit stukje tekst zal er nog zo kort mogelijk beschreven moeten worden wat de resultaten zijn van het onderzoek en de discussie. Zie: https://explorable.com/writing-an-abstract

## Management summary
TODO: 

    Het probleem: wat is de aanleiding en waarom wordt het advies uitgebracht?
    Het advies: welke maatregelen worden voorgesteld om het probleem op te lossen?
    De argumentatie: waarom worden deze maatregelen voorgesteld?
    De consequenties: wat zijn de kosten en welke werkzaamheden moeten er verricht worden om de maatregelen door te voeren?


# Table of contents
1. [Preface](#1-preface)
1. [Introduction to robot arms](#2-introduction-to-robot-arms)
    1. [Rescue Operations](#i-rescue-operations)
        1. [Fire](#2ia-fire)
        1. [Gasleak](#2ib-gasleak)
        1. [Earthquake](#2ic-earthquake)
    1. [Available arms](#2ii-available-arms)
    1. [Properties](#2iii-properties)
1. [Comparisons](#3-comparisons)
1. [Recommendations](#4-recommendations)
1. [References](#References)

# 1. Preface
As the abstract has clarified us, this research paper is about robot arms for Swarm Robotics. The main problem of finding a proper robot arm is that robot arms can be expensive depending on their precision and lifting power. It will also come in handy if we know how precise this robot arm has to be for these so called, “rescue operations”. Of course, rescue operations is a very broad term, so we will explain that in section [2.i](#2i-rescue-operations).


# 2. Introduction to robot arms
First of all, let us explain to you what robot arms are.

> ‘‘Robot arms are programmable multi-functional mechanical devices designed to move material, parts, tools, or specialized devices through variable programmed motions to perform a variety of tasks.’’ (OSHA, 2019a)

Robot arms are expensive. Not per say the production of it, but the development of it. We're talking the development of the software here. But why? Well, robot arms may not look complex at all, (they look like arms after all) but it requires very complex algorithms to determine what the fastest way from point A to B is, in 3D space. There are some solutions for this, such as using feedback by using camera's (2013a, 1 November). Look at this undermentioned picture for example. There are a lot of axis you have to take into account.

<p align="center">
  <img src="https://global.yamaha-motor.com/business/robot/lineup/ya/ya-7/img/index/img_001.jpg" width="70%" height="70%">
</p>


## 2.i Rescue Operations
Rescue Operations. What are they? Rescue operations are operations /../
<br><br>
In the following few headings, the sub-questions of the main question will be answered.

### 2.i.a Fire
The following sub-question applies to this heading:
> In event of a fire, how can a robot arm assist (a person/victim) without harming the victims and itself?

Let's kick off this section by looking at the types of fires there are and when the material most robot arms are made off, will melt. (Wildfire Today, 2012b), (Cityfire, 2018a).

|Type                 |Temperature  |
|---------------------|:-----------:|
|Forest fire          |      ~800 °C|
|Log fire flames      |      ~600 °C|
|Bonfire flames       |    ~1.100 °C|
|Bunsen burner flames |    ~1.100 °C|

Note that the temperatures listed above, are the temperatures of the core of the fire. Our robot arm will not work in the core of the fire, but just next to it or near it. The temperature will thus vary considerably. Think about keeping your hands over a fire. The temperature on your hands will not be 600 °C obviously.

And, as discussed, the table of certain materials.

|Material         |Melting temperature |
|-----------------|:------------------:|
|Stainless Steel  |             1,510°C|
|Aluminum         |               660°C|
|Cast iron        |     1,127 – 1,204°C|

Now, let's take a look at extinguishing a fire. A fire needs three elements: oxygen, fuel and sufficient temperature. In order to extinguish a fire, one of these three elements needs to be removed.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/99/Fire_tetrahedron.svg/1024px-Fire_tetrahedron.svg.png" width="50%" height="50%">
</p>

The following enumeration will show what to think about, when removing one of the three elements. Please note that removing fuel from the fire does not prevent the fire from continuing burning. It just prevents the fire from spreading. The fire continues to burn until the fuel that is still available is consumed. This method is commonly used in wildfires (Auburn University, n.d.).

* Oxygen
    * Fire blankets;
    * Water;
    * Fire retardants
    * Dirt;
    * Foam;
* Heat (comparable with reducuing the oxygen level)
    * Water;
    * Dirt;
    * Foam;
    * Spreading the fuel to reduce reduce radiant heat
* Fuel
    * Chemical retardants (removes fuel by 'coating' a barrier that protects the fuel from preheating as well as cutting off the supply of oxygen)

Now allow us to return to the sub-question of this section. Depending on what kind of fire the robot arm will assist in, it can surely grab a fire blanket/fire retardant and put/spray this over the fire for example. Fire blankets/fire retardants are not heavy per say, so it does not require a robot arm with a high payload. A robot arm can also hold a fire hose to assist fire-fighters. The robot must be heavy enough to withstand the water pressure that comes out of the hose. <br>

Furthermore, fire can release toxic gasses, and proper gas masks needs to be worn to prevent inhaling these toxic gasses. A robot arm attached to a vehicle can pick up and bring a gas mask to the victim. The disadvantage is however, that the victim needs to be in a state that he/she is still able to apply this gas mask to him-/herself. The weight of the gas mask will be discussed in section [2.i.b Gasleak](#2ib-gasleak).

### 2.i.b Gasleak
The following sub-question applies to this heading:
> In event of a gasleak, how can a robot arm assist (a person/victim) without harming the victims and itself?

First of all, let us take a look at the following table (Gas Alarm Systems, 2012a). The table describes the top 3 most toxic gasses currently known. Also, it'll give you an indication of the side effects and how it is recognized (signs).

| Number | Gas | Side effects | Signs |
|--------|-----|--------------|-------|
| 1 | Hydrogen Sulphide |  - Reduces body’s oxygen supply <br> - Damages the cells nervous system <br>  - Paralyzes the respiratory system <br> | - Immediate coma |
| 2 | Arsine | - Destroys red blood cells | - Severe headaches <br> - Haemolytic anaemia <br> - nephropathy <br> |
| 3 | Chlorine |  - Irritates the respiratory system <br> - Lung damage |  - Coughing <br> - Vomiting <br> |

Humans are not capable of keeping alive long in these environments as you understand. Either a gas mask will be required or external oxygen. So, that's why our robot arm will transport a gas mask or external oxygen. A gas mask is not very heavy and external oxygen doesn't have to be either. In planes for example, they use a Chemical Oxygen Generator (COG) because a plane has to be light as possible so you can't just bring a huge metal oxygen tank. The COG will generate oxygen based on chemical reactions (Skybrary, 2016a). Example of a COG:

<p align="center">
  <img src="https://2.bp.blogspot.com/-ly5oKKHYRPs/WRRfSzwrBnI/AAAAAAAAFYQ/dhQRDiIOdRYY7d_oL_m93RLrRSPRQDH-QCLcB/s1600/7.png" width="40%" height="40%">
</p>

So, COGs and gas masks. That is how a robot arm can assist in gas leaks. The robot arm attached to a vehicle will enter the toxic area and bring the gas mask/COG with him. Then, either a fire brigade assistant can put this gas mask on the victim, or the victim can do this by himself, if he is still physically/mentally able to do this. Of course the fire brigade assistant can bring a gas mask to the victim himself, but that requires at least one of his hands (maybe more if there are multiple victims) which may interfere with his activities in the toxic area.
<br><br>
Another way a robotic arm can help in such areas, is by searching and locating victims. Once a victim has been found, the robot will send location information to notify the rescue workers. In order to recognize a victim, a camera can be placed in the robot end effector. This way, a robot arm with >= 4 DOF (Degrees Of Freedom) can perform a detailed inspection on the victim, a lot of body parts of the victim can be checked. With such a camera arm the robot would also be able to move through small holes in walls to check for victims on the other side.
 
### 2.i.c Earthquake
The following sub-question applies to this heading:
> In event of an earthquake, how can a robot arm assist (a person/victim) without harming the victims and itself?

First of all, earthquakes themselves aren't really dangerous themselves. People can't be shaken to death by an earthquake. Some movies however may show sudden pieces of ground opening up and people falling into it. But that never happens in real life.
<br>
The first main hazard of earthquakes is that it can cause damage to other objects (buildings in particular) by the shaking of the earthquake or by the ground beneath the objects settling to a different level than it was before (subsidence).

<p align="center">
  <img src="https://static.boredpanda.com/blog/wp-content/uploads/2016/08/italy-earthquake-before-after-fb__700-png.jpg" width="80%" height="80%">
</p>

Another very dangerous occurence during earthquakes is 'liquefaction'. Liquefaction is when pieces of sand or soil get mixed with water during moderate or strong earthquakes. This will result in the ground becoming very soft, thus causing a quicksand effect. If this happens underneath a building it may start to lean, tip over, or sink several feet. After the shaking, the ground firms up again and the water settles back to its original position. This hazard obviously will only happen when the area has groundwater in it. <br>

Earthquakes can also cause ground displacements. Ground displacements are movements of multiple surfaces relative to each other. This can cause grooves in a surface if the movement relative of each other, are opposite. But it really depends on what the movements are of the surfaces (UPSeis, n.d.). One example is shown below.

<p align="center">
  <img src="https://patbrittenden.files.wordpress.com/2012/01/ch-quake.jpg" width="50%" height="50%">
</p>

A robot arm can assist in a variety of tasks in earthquake environments. If a victim gets covered under large pieces of debris, a robot arm attached to a vehicle can lift these pieces of (heavy) debris and free the victim potentially.

## 2.ii Available arms
In this section we will show you the robot arms we found in an enumeration, based on the requirements talked about earlier. We will also list the arms we currently have in stock at our Computer Science Lab. It is good to know that customized, professional and accurate robot arms are not just for sale on some webpage. There are companies who specializes in robotic arms. We are a University of Applied Science, so we probably won't spend €90.000 (RobotWorx, n.d.) on a robotic arm. However, for this research, we will ignore this available budget, and still compare it with other robotic arms. See the enumeration below. Furthermore, we won't go into too much detail in this enumeration. Note that the Do It Yourself robot arm is just an example. You can make it as big, or as small as you'd like. 

* [DIY 4DOF Acryl Robot Arm](https://elektronicavoorjou.nl/product/diy-4dof-acryl-robot-arm/)
* DIY robot arm, see [example](https://howtomechatronics.com/tutorials/arduino/diy-arduino-robot-arm-with-smartphone-control/)
* [uArm Swift Pro Main Body](https://store.ufactory.cc/products/uarm-swift-pro-main-body-accessories-excluded)
* [UR3 from Gibas](https://www.universal-robots.com/media/240787/ur3_us.pdf)
* [Advanced Rootic Manipulator (ARM 3.0) Closed Loop](https://www.robotshop.com/ca/en/advanced-robotic-manipulator-arm-3.html)
* [FANUC R-1000iA/120F-7B](https://www.fanuc.eu/be/en/robots/robot-filter-page/r-1000-series/r-1000ia-120f7b)

Currently available in the Computer Science Lab:
* A few [uArm Swift Pro's](https://store.ufactory.cc/products/uarm-swift-pro-main-body-accessories-excluded)
* 1x [UR3 from Gibas](https://www.universal-robots.com/media/240787/ur3_us.pdf)
* Multiple [4DOF robot arms](https://elektronicavoorjou.nl/product/diy-4dof-acryl-robot-arm/)


## 2.iii Properties
Before we are going to show you a table of all the robot arms that might be a potential candidate for this project, we would like you to show the next graph. Keep in mind that this graph is not 100% accurate, it is just an indication. This information is based on the following source (Yaskawa America, Inc.- Motoman Robotics Div, n.d.) plus the robot arms we found, further in the document.

<p align="center">
  <img src="https://i.imgur.com/214BfSQ.jpg" width="70%" height="70%">
</p>

This graph shows almost an exponential growth in the weight/payload ratio. The more the payload gets, the more the weight gets, exponentially.

https://www.robotshop.com/en/dr-robot-jaguar-robotic-arm.html <br>
https://www.robotshop.com/en/advanced-robotic-manipulator-arm-3.html

# 3. Comparisons
### [DIY 4DOF Acrylic Robot Arm](https://elektronicavoorjou.nl/product/diy-4dof-acryl-robot-arm/)
* Weight: 450g
* Max payload:
* Range:
* Input: 5 Volt, 2 Ampère
How to program:
Any hardware that can control 4 servos at the same time can be used to program this robot arm.

Pros:
* Manual control build in

Cons:
* No rotation for end effectors
* Implementing movement algorithm necessary

### [DIY robot arm](https://howtomechatronics.com/tutorials/arduino/diy-arduino-robot-arm-with-smartphone-control/)

Entirely customizable

How to program:
Any hardware that can control 6 servos at the same time can be used to program this robot arm.(As by the design specified in the link)

Pros:
* Can be tailor made for a specific robot

Cons:
* Has to be 3d printed
* Implementing movement algorithm necessary
 

### [uArm Swift Pro](https://store.ufactory.cc/products/uarm-swift-pro-main-body-accessories-excluded)
[Details](http://download.ufactory.cc/docs/en/uArm%20Swift%20Pro%20Quick%20Starter%20Guide%20v1.0.17_20180619.pdf)
* Available in our Technical Computer-science lab
* Weight: 2.2kg
* Max payload: 500g
* Range: ~50mm - ~320mm
* Input Voltage: 12V DC

How to program:
https://github.com/uArm-Developer
* Pyhton via serial
* c++ via serial
* ROS

Pros:
* Customizable
* Bluetooth
* Build in Extension port for end effectors

Cons:
* Weight constraints limited to certain angles
* Only 180 degrees of range
* End effectors can’t be rolled over
 
### [UR3 from Gibas](https://www.universal-robots.com/media/240787/ur3_us.pdf)
* Available in our Technical Computer-science lab
* Weight: 11kg
* Max payload: 3kg
* Range: 500mm
* Input Voltage: 24V

How to program:
* [DSL: URScript via a TCP/IP socket](http://me.umn.edu/courses/me5286/robotlab/Resources/scriptManual-3.5.4.pdf)
* User interface

Pros:
* Highest range of available robots
* Can carry the most weight
* Force control
* Fully supported script language
* 360 degrees of range

Cons:
* Meant for static use


## 4. Recommendations
## References
<details>
(OSHA, 2019a) OSHA. (z.d.). OSHA Technical Manual (OTM) | Section IV: Chapter 4 - Industrial Robots and Robot System Safety | Occupational Safety and Health Administration. Retrieved 10 March 2019, from https://www.osha.gov/dts/osta/otm/otm_iv/otm_iv_4.html
<br><br>
(IEEE Xplore, 2013a) IEEE Xplore. Controlling a robotic arm in the 3D space with stereo vision - IEEE Conference Publication. Retrieved at 11 March 2019, from https://ieeexplore.ieee.org/document/6716380
<br><br>
(RobotWorx. (n.d.)). RobotWorx. How Much Do Industrial Robots Cost? Retrieved 11 March 2019, from https://www.robots.com/faq/how-much-do-industrial-robots-cost
<br><br>
(Yaskawa America, Inc.- Motoman Robotics Div, n.d.) Yaskawa America, Inc.- Motoman Robotics Div. (n.d.). Motoman Industrial Robots. Retrieved 12 March 2019, from https://www.motoman.com/industrial-robots
<br><br>
(Gas Alarm Systems, 2012a) Gas Alarm Systems. (2012, 23 March). 3 of the World's Most Dangerous Gases. Retrieved 14 March 2019, from https://www.ranker.com/list/3-of-the-world_s-most-dangerous-gases/gas-detection
<br><br>
(Skybrary, 2016a) SKYbrary. (2016a, 17 juli). Chemical Oxygen Generators - SKYbrary Aviation Safety. Retrieved 14 March 2019, from https://www.skybrary.aero/index.php/Chemical_Oxygen_Generators
<br><br>
(Wildfire Today, 2012b) Wildfire Today. (2012, 13 September). At what temperature does a forest fire burn? Retrieved 17 March 2019, from https://wildfiretoday.com/2011/02/26/at-what-temperature-does-a-forest-fire-burn/
<br><br>
(Cityfire, 2018a) Cityfire. (2018, 6 December). The Temperature Of Fire - City Fire Protection. Retrieved 17 March 2019, from https://www.cityfire.co.uk/news/the-temperature-of-fire/
<br><br>
(Auburn University, n.d.) Auburn University. (n.d.). Breaking the Fire Triangle. Retrieved 17 March 2019, from https://www.auburn.edu/academic/forestry_wildlife/fire/breaking.htm
<br><br>
(UPSeis, n.d.) UPSeis. (n.d.). What Are Earthquake Hazards? Retrieved March 20, 2019, from http://www.geo.mtu.edu/UPSeis/hazards.html