# MailSlot 
A mailslot is a mechanism for one-way interprocess comminucation(IPC)\
Applications can store messages in a mailslot\
Mailslots, on the other hand are a simple way for process to broadcast messages using datagram. \
If datagrams are lost there will be no confirmation. \
In Mailslots, Only CLIENT write the message which stored on amilslots and later SERVER can retrieve or read the message. \
