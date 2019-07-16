import sys
import os
import time
from random import randrange
from APIlib import api42



def delayS(_time, _intervale):
    count = 0
    while (count <= _time):
        time.sleep(_intervale)
        count += _intervale
        os.system("osascript -e " + '"' + "set volume output volume 100" + '"' + ";")




def Troll1(_API):
    os.system("afplay -v 0.2 MusAmb.mp3&")
    delayS(5, 0.6)
    _API.loadUProfile(_API.getRandomProche())
    os.system("say -v amelie Pour un max de sensation, Envoyer sexe, au " + _API.getUnum()+"&")
    delayS(11, 0.6)
    os.system("afplay -v 0.2 MusAmb.mp3&")
    delayS(5, 0.6)
    os.system("say -v amelie Pour un max de sensation, Envoyer sexe, au " + _API.getUnum()+"&")

def Troll2(_API):
    os.system("afplay -v 0.2 MusFun.mp3&")
    time.sleep(5)
    if (_API.getsexe() == 0):
        os.system("say -v thomas Trop bien, je suis trop fort je mappelle "+  _API.getDisplayName() + ", et je suis levels " + _API.getlevels())
        time.sleep(2)
        os.system("say -v thomas Je suis vraiment le plus fort, venez me voir, je suis"+_API.getPos())
    else:
        os.system("say -v amelie Trop bien, je suis trop forte je mappelle "+  _API.getDisplayName() + ", et je suis levels " + _API.getlevels())
        time.sleep(2)
        os.system("say -v amelie Je suis vraiment la plus forte, venez me voir, je suis"+_API.getPos())

def Troll3(_API):
    time.sleep(0.6)
    log = _API.getRandomProche()
    _API.loadUProfile(log)
    if (_API.getUsexe() == 0):
        os.system("say -v thomas Ta guele," + _API.getUDisplayName())
    else:
        os.system("say -v amelie Ta guele," + _API.getUDisplayName())

def Troll4(_API):
    if (_API.getsexe() == 0):
        os.system("say -v thomas Je suis "+ _API.getDisplayName() +", et je vous partage ma chanson praifairee, Vous etes pret ?")
        os.system("say -v thomas 3, 2, 1, sai est parti!")
        os.system("afplay -v 0.2 MoiJai.mp3&")

    else:
        os.system("say -v thomas Je suis "+ _API.getDisplayName() +", et je vous partage ma chanson praifairee, Vous etes pret ?")
        os.system("say -v thomas 3, 2, 1, sai parti!")
        os.system("afplay -v 0.2 MoiJai.mp3&")


victime_l = os.environ['USER']

_API = api42(victime_l)
time.sleep(0.6)
_API.loadLocation()


RandTroll = randrange(4)
RandTroll = 1

if RandTroll == 0:
    Troll1(_API)
elif RandTroll == 1:
    Troll2(_API)
elif RandTroll == 2:
    Troll3(_API)
elif RandTroll == 3:
    Troll4(_API)

