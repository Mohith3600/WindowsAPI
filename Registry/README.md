Registry 
The Registry is a centralized , hierarachical database for application and system configuration information 
Registry stored in key/value pair 

The Registry contains following information 
1.Windows Version number, build number & Registered user 
2.Information about the computer's process type ex:Intel I3,I5,I7 
3.User specific information 
4.Security information 
5.Installed Services 
6.File name and extension 

Registry Structure 
The Registry is access through Keys and Values Name.
We know that in windows each and everything is treated as object while in Linux as a File.
Registry Contains basically Two Elements.
• Keys – Keys are object which is Similar to directory.
-Each Keys can contain Sub-keys also.
• Values – Values (or Information) are some bit such as files in a folder.
-Access through path name

Registry Management
Registry management functions allows to query and modify key/value pairs.
It can create new subkeys and corresponding key/value pair.

Key Management
Key Management functions allows to open named keys.
Enumerate Subkeys of open key and create new keys.

Registry Hive
Registry Hive is logical group of Keys, Subkeys and Values in the Registry that has a set of Supporting files containing backups of its data.

which program to use to open a particular kind of file 
type of icon to show the type of file 


1.HKEY_CLASSES_ROOT 
This root key defines the standarad class objects by windows 
Class Object : A named group of functions that defines what you can do with the object it represents 
The system will know everything about a particular software to use to open a file 
The icon to be showed 

2.HKEY_CURRENT_USER
Windows supports multiple users 
Each user has their own wallpapers and screensavers 
Store the settings of the current user

3.HKEY_LOCAL_MACHINE 
contains all the data for our systems non user specific configurations and this encompasses every device and every program in the PC 
like what programs automatically run when the computer turns on

4.HKEY_USERS 
Stores all of the personalized information for all users on a PC 



