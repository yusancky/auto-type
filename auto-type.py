from time import sleep
from pynput import keyboard

def get_file_name():
    tmp = input('Please input the path of the file you want to type and press the [enter].\nAfter that, please wait 3 seconds, and it will start to type. ')
    try:
        with open(tmp):
            return tmp
    except FileNotFoundError:
        return get_file_name()

file_name = get_file_name()
sleep(3)
my_keyboard = keyboard.Controller()
with open(file_name) as file:
    line = file.readline()
    while line:
        for i in range(len(line)):
            my_keyboard.type(line[i])
        line = file.readline()
