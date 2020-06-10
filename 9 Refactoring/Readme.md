# Refactoring
Look at the `message.h` header. What options do you have to improve the usability of that API?

Use the `sendFrame` function from `network_layer.h` to implement a way for the user to send Messages.

Just choose a hard coded source address that is set in `main.c`.
The message type is supposed to be the first field in the payload
of a frame.

Find out how to use the ADDRESSING_FORMAT field
by looking at the implementation in `network_layer.c`.