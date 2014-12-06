eechidna
========

The Mother of All Coding Project Monsters

So we have a layout of the eEchnida system will generally make everything
fall and fit into. At least in various internal systems. These might even
be able to be made into various directory systems... if you enjoy pissing 
off System Administrators. As that is TOTES a good idea. I suggest you piss 
off as many System Administrators as possible... they all love it and are 
total masocists for your shullbit.

Root : /
 * /Configuration
 : This is pretty much /etc. Except with extra letters. I know, I'm 
 : pretty much Hitler here
 * /System
 : This is pretty much /sbin. Likely will have some mapping done for 
 : some terribly handled and written programs.
 * /Basics
 : this is /bin. This should only contain basic tools and utilities 
 : for running your system
 * /Devices
 : Well, there is no way you'd guess it, but this is /dev. I mean, it is 
 : pretty hard to figure out this match up, and I am not being at all 
 : intuitive here
 * /Userland
 : This is typically anything that should be located in /usr
 * /Outsideland
 : Typically /share is meant for outside network stuff. I mean, on a root 
 : level. Actually, I have no idea why you'd have a /share on the root 
 : level... apart from maybe as yet another system management horror story.
 :
 : Also anything that is /opt at the root folder level will also be tossed 
 : into outsideland. Sorry... but a root level /opt folder is fucking 
 : retarded
 * /Anomoly
 : This is the previous /var folder. Since var included logs, spools and 
 : all kinds of shit tossed between various daemon concepts... it will be 
 : shifted over to Anomoly... as there isn't much that works better here.
 * /Temporary
 : This... is kind of a bullshit folder. I mean, yeah, /tmp is its own 
 : bullshit folder... there is no reason that we cannot have a system for 
 : temp file trash collection set up in /var. The /tmp folder is likely only
 : kept for really old programs and idiot uses from the 1970s or some 
 : bullshit.
 * /Boot
 : Well this is pretty much /boot... but NOW with a capital B. So if you 
 : Don't have enough terminal memory to handle 8bit ASCII and are limited 
 : to 7bit ASCII, or less bit required EBCDIC... then... you'd be screwed 
 : either way, as the additional bit allows for LOWERCASE letters... 
 : fucknuts.
 * /BaseLibrary
 : ... dear... this had better be some pretty basic shit that should be 
 : stored in /lib. The "BASE" should say you should... actually I think 
 : this might be an invitation for more numbnutsery.
 : 
 : Also will need to include 64bit variations of libraries in here.
 : Possibly with 64 in the extension as a fucking clue. With 32 bit libraries 
 : stored next to 16bit, 12bit, 8bit, 7bit, 6bit and 5bit libraries...
 : because let's fucking allow all kinds of fucking idiotic bullshit with 
 : how linkers are set up.
 :
 : Yes... I am aware that the different level of bit changes how the 
 : libraries are addressed... and just out of being pissed off, I want to 
 : start having lib5, lib12 and whatnot in the root level of various 
 : systems with libraries compiled for systems with a 5bit WORD, 12bit WORD
 : and all that.
 
So yeah... basic idea of what I will be fucking with. I will be messing 
with configuration files of a Arch system set up on a bitty box to 
document how much fucking fail this causes in the system itself.

Trust me... this is going to create some FANTASTIC results... which I'll 
probably just YouTube so you can throw into your "stupid user tricks" for
how it likely will end up working.

Though... I seriously fucking hate the whole lib64 bullshit that Linux is 
doing. You know, you could probably have a 64.o type in your library folder.
Maybe even have it so you don't need the library to be prefixed with "lib"
when in that folder and just tell the linker, "oh... check if we need to 
prefix lib onto the library for how it is being called". As I imagine just 
dropping lib when the item is called will cause issues... actually, dropping
the lib in storage would... swagever, still a thought in progres.
