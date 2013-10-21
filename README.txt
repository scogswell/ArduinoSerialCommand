An Arduino library to tokenize and parse commands received over a serial port. 

Initially documented here: http://awtfy.com/2011/05/23/a-minimal-arduino-library-for-processing-serial-commands/

An alternate version of this library is available as https://github.com/kroimon/Arduino-SerialCommand 

This version is the one on Github. 

/******************************************************************************* 
SerialCommand - An Arduino library to tokenize and parse commands received over
a serial port. 
Copyright (C) 2011-2013 Steven Cogswell  <steven.cogswell@gmail.com>
http://awtfy.com

Version 20131021A.   

Version History:
May 11 2011 - Initial version
May 13 2011 -	Prevent overwriting bounds of SerialCommandCallback[] array in addCommand()
			defaultHandler() for non-matching commands
Mar 2012 - Some const char * changes to make compiler happier about deprecated warnings.  
           Arduino 1.0 compatibility (Arduino.h header) 
Oct 2013 - SerialCommand object can be created using a SoftwareSerial object, for SoftwareSerial
           support.  Requires #include <SoftwareSerial.h> in your sketch even if you don't use 
           a SoftwareSerial port in the project.  sigh.   See Example Sketch for usage. 
Oct 2013 - Conditional compilation for the SoftwareSerial support, in case you really, really
           hate it and want it removed. 

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
***********************************************************************************/