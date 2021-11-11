# CreateFile()
Create File can be used to create a file or open an existing file 
The return type of CreateFile API is Handle 

Handle : A handle is an abstract reference to reference , variable to hold a file 
		 When we want to open a file , first the Operating System will locate the file 
		 File Handle is a number that OS temporarily assign to a file 

CloseHanlde() : It is used to close the handle 

Desired Access : Generic read and Generic write or both 

Share Mode : 0 prevenets other process from opening a file or device if they request 			  delete read , or write access  
