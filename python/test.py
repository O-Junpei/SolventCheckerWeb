import serial
import re
def main():
    with serial.Serial('COM3',115200,timeout=1) as ser:

        while True:
          #      if(rcs620s.idm[i] / 0x10 == 0) lcd.print(0);

            c = ser.readline()
            #print(type(c))
            #print(c)
            my_str = str(c)
            print(type(my_str))
            print(my_str)
            words = my_str.split(" ")

            if len(words)>2:
              print(words[1])
            
            #print(c.decode("shift_jis"))
            #print(c.decode("UTF-8"))

        ser.close()

if __name__=="__main__":
    main()