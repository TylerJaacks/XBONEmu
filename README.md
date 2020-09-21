# XBONEmu
Here is the home of the first Xbox One emulator (It's not really an emulator I will discuss later the technique for running Xbox One games), and no this is not a scam. I want to claify somethings about this project 1. this isn't really an emulator and more of a patcher/loader/thingy for loading Xbox One executables but in theory you should be able to run the binaries as is on your Windows 10 computer. 2. There is a lot of hard work that is needed to get this to a functioning state and as of now I am the only one working on this and I work 20 hours and am a full time students so I can only commit when I have time so. So I hope others get interested and a contribute. Really looking for people with Xbox One internals knowledge and Windows 10 internals knowledge. 3. Even if this emulator thingy is finished it would only be able to run homebrew applications and code compiled with the SDK because currently it is impossible to decrpyt and dump games. That being said if you have a decrypted copy of game and it dumped you should be able to in theory run it.

# Investigating the Xbox One Binaries

We need to fully understand the structure of the Xbox One binaries such as how the compare and contrast to that of there Windows (Windows Portable Executable or Windows PE for short) counterparts. This would allow us to know if there were any changes we would need to make to make sure that these binaries can even run on the host machine.

# Rerouting Xbox One Libaries

We need to get the Xbox One Binaries which are very similar to that of WinPE binaries to redirct from the Xbox One SDK libaries and kernel to the Windows 10 libaries and kernel. We could use [Microsoft Detours](https://github.com/microsoft/Detours) to redirect calls to these Xbox Libaries to that of ones on Windows. I think that using Microsoft Detours would be a good idea to start with.

# Example of How We Should Reroute

![Xbox One API Rerouting](./Images/rerouting.png)

This is based on an example application that I made using the Xbox One SDK.

# Resources

[Inject your code to a Portable Executable file](https://www.codeproject.com/Articles/12532/Inject-your-code-to-a-Portable-Executable-file#Prerequisite1)

[Using Detours](https://github.com/microsoft/detours/wiki/Using-Detours)

[Xbox Research Engineering Wiki](https://xosft.dev/wiki/)

[Loading Windows PEs](https://github.com/JeremyWildsmith/PELoader)
