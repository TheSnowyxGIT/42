import json
import urllib2
import urllib
import unicodedata
from random import randrange

class api42:

	_login = "none"
	_TOKEN = "none"
	_clientID = "958a4e6644dd5787e9e23644f0c4314586147968d34c83b6974193d6f0dabdd4"
	_clientSecret = "223b3aef0dc7f228f1d47193f8d244d8f5eb42a25981347aadcab7e1dcfb6d5b"
	_victime_profil = {}
	_proche_profil = {}
	_victime_location = {}
	_prenom = "none"
	_nom = "none"

	def __init__(self, login):
		self._login = login
		self._TOKEN = self.getAccessToken()
		self.loadProfile()
		self.setDisplayName()



	def loadProfile(self):
		self._victime_profil = self.getResponseJson('https://api.intra.42.fr/v2/users/'+ self._login)

	def loadUProfile(self, login):
		self._proche_profil = self.getResponseJson('https://api.intra.42.fr/v2/users/'+ login) 

	def loadLocation(self):
		self._victime_location = self.getResponseJson('https://api.intra.42.fr/v2/users/'+ self._login + "/locations") 

	# Get The Token
	def getAccessToken(self):
	    payload = {'grant_type': "client_credentials", 'client_id': self._clientID, 'client_secret': self._clientSecret}
	    req = urllib2.Request("https://api.intra.42.fr/oauth/token", data=urllib.urlencode(payload))
	    response = urllib2.urlopen(req).read()
	    fjson = json.loads(response)
	    return fjson["access_token"]

	def getResponseJson(self, url):
	    req = urllib2.Request(url)
	    req.add_header('Authorization', 'Bearer '+ self._TOKEN)
	    resp = urllib2.urlopen(req).read()
	    return json.loads(resp)

	def setDisplayName(self):
		self._prenom = self.remove_accents(self._victime_profil['first_name'])
		self._nom = self.remove_accents(self._victime_profil['last_name'])

	def remove_accents(self, input_str):
		nfkd_form = unicodedata.normalize('NFKD', self.make_unicode(input_str))
		only_ascii = nfkd_form.encode('ASCII', 'ignore')
		return only_ascii

	def make_unicode(self, input):
	    if type(input) != unicode:
	        input =  input.decode('utf-8')
	        return input
	    else:
	        return input


	#--------------- FONCTIONS DE RECHERCHE -------------------#
	def getParamPcProche(self, actuel_loc):
		etage = actuel_loc[1]
		rangee = actuel_loc[actuel_loc.index('r') + 1:actuel_loc.index('p')]
		position = actuel_loc[actuel_loc.index('p') + 1:]
		param = ""
		if (int(rangee) != 1 and int(rangee) != 13):
			x = int(position) - 3 
			y = int(rangee) - 1
			for i in range (3):
				nmax = 23
				if (y == 3 or y == 8):
					nmax = 21
				elif (y == 5):
					nmax = 22
				elif (y == 9 or y == 6):
					nmax = 20
				x = int(position) - 3 
				for a in range (7):
					if (y != int(rangee) or x != int(position)):
						if ((y != 1 and y != 13) or x <= 14):
							if ((y != 1 and y != 13) or ((x > 7 or int(position) <= 7) and (x <= 7 or int(position) > 7))):
								if ((x > 0 and x < nmax) and (y < 14 and y > 0)):
									param += "e"+str(etage)+"r"+str(y)+"p"+str(x)+","
					x += 1
				y += 1
		else:
			x = int(position) - 3 
			y = int(rangee) - 1
			for i in range (3):
				nmax = 23
				if (y == 3 or y == 8):
					nmax = 21
				elif (y == 5):
					nmax = 22
				elif (y == 9 or y == 6):
					nmax = 20
				x = int(position) - 3 
				if (y != int(rangee)):
					x += 9
				for a in range (7):
					if (y != int(rangee) or x != int(position)):
						if ((x > 0 and x < nmax) and (y < 14 and y > 0)):
							if ((y != 1 and y != 13) or ((x > 7 or int(position) <= 7) and (x <= 7 or int(position) > 7))):
								param += "e"+str(etage)+"r"+str(y)+"p"+str(x)+","
					x += 1
				y += 1
		param = param[0:-1]
		return param



	#-------------- FIN FONCTIONS DE RECHERCHE -----------------#

	#--------------- FONCTIONS D'HUMILIATION ---------------------#

	def getRandomProche(self):
		actuel_loc = self._victime_location[0]['host']
		param = self.getParamPcProche(actuel_loc)
		vals = self.getResponseJson('https://api.intra.42.fr/v2/locations?filter[host]='+ param +'&filter[active]=true')
		logins = []
		for i in range(len(vals)):
			logins.append(vals[i]['user']['login'])
		randuser = randrange(len(logins))
		return logins[randuser]
		

	def getNoteGenerale(self):
	    nbProjects = len(self._victime_profil['projects_users'])
	    somme = 0
	    nbpfinished = 0;
	    nb = 0
	    for i in range(nbProjects):
	        if (self._victime_profil['projects_users'][i]['status'] == 'finished'):
	            if (self._victime_profil['projects_users'][i]['project']['name'][10:14] == 'Exam'):
	                nb += 3
	                somme += 3 * self._victime_profil['projects_users'][i]['final_mark']
	                nbpfinished += 1
	            elif (self._victime_profil['projects_users'][i]['project']['name'][10:11] == 'C'):
	                nb += 2
	                somme += 2 * self._victime_profil['projects_users'][i]['final_mark']
	                nbpfinished += 1
	            elif (self._victime_profil['projects_users'][i]['project']['name'][10:15] == 'Shell'):
	                nb += 2
	                somme += 2 * self._victime_profil['projects_users'][i]['final_mark']
	                nbpfinished += 1
	            elif (self._victime_profil['projects_users'][i]['project']['name'][10:13] == 'Rush'):
	                nb += 1
	                somme += 1 * self._victime_profil['projects_users'][i]['final_mark']
	                nbpfinished += 1
	            else:
	                nb += 4
	                somme += 4 * self._victime_profil['projects_users'][i]['final_mark']
	                nbpfinished += 1
	    if nb == 0:
	        return [0,0]
	    return (somme / nb)


	def getNoteExam(self):
	    nbProjects = len(self._victime_profil['projects_users'])
	    somme = 0
	    nb = 0
	    for i in range(nbProjects):
	        if (self._victime_profil['projects_users'][i]['status'] == 'finished'):
	            if (self._victime_profil['projects_users'][i]['project']['name'][10:14] == 'Exam'):
	                nb += 1
	                somme += 1 * self._victime_profil['projects_users'][i]['final_mark']
	    if nb == 0:
	        return [0,0]
	    return (somme / nb)


	def getNoteRush(self):
	    nbProjects = len(self._victime_profil['projects_users'])
	    somme = 0
	    nb = 0
	    for i in range(nbProjects):
	        if (self._victime_profil['projects_users'][i]['status'] == 'finished'):
	            if (self._victime_profil['projects_users'][i]['project']['name'][10:14] == 'Rush'):
	                nb += 1
	                somme += 1 * self._victime_profil['projects_users'][i]['final_mark']
	    if nb == 0:
	        return [0,0]
	    return (somme / nb)

	def getNoteShell(self):
	    nbProjects = len(self._victime_profil['projects_users'])
	    somme = 0
	    nb = 0
	    for i in range(nbProjects):
	        if (self._victime_profil['projects_users'][i]['status'] == 'finished'):
	            if (self._victime_profil['projects_users'][i]['project']['name'][10:15] == 'Shell'):
	                nb += 1
	                somme += 1 * self._victime_profil['projects_users'][i]['final_mark']
	    if nb == 0:
	        return [0,0]
	    return (somme / nb)


	def getNoteC(self):
	    nbProjects = len(self._victime_profil['projects_users'])
	    somme = 0
	    nb = 0
	    for i in range(nbProjects):
	        if (self._victime_profil['projects_users'][i]['status'] == 'finished'):
	            if (self._victime_profil['projects_users'][i]['project']['name'][10:11] == 'C'):
	                nb += 1
	                somme += 1 * self._victime_profil['projects_users'][i]['final_mark']
	    if nb == 0:
	        return [0,0]
	    return (somme / nb)
	    

	#Obtenir le sexe de la personne (1 == female / 0 == male)
	def getsexe(self):
		prenom = self._prenom.replace(' ', '+')
		prenom = self.remove_accents(prenom)
		urlsexe = "http://api.namsor.com/onomastics/api/json/gendre/" + prenom + "/fr"
		req = urllib2.Request(urlsexe)
		resp = urllib2.urlopen(req).read()
		fjson = json.loads(resp)
		if (fjson['gender'] == 'female'):
			return 1;
		else:
			return 0;
		return 1;

	def getUsexe(self):
		prenom = self.remove_accents(self._proche_profil['first_name'])
		prenom = prenom.replace(' ', '+')
		prenom = self.remove_accents(prenom)
		urlsexe = "http://api.namsor.com/onomastics/api/json/gendre/" + prenom + "/fr"
		req = urllib2.Request(urlsexe)
		resp = urllib2.urlopen(req).read()
		fjson = json.loads(resp)
		if (fjson['gender'] == 'female'):
			return 1;
		else:
			return 0;
		return 1;

	def getnum(self):
	    num = self._victime_profil['phone']
	    if (num[0:3] == '+33'):
	        _str = "0" + num[3:4] + ", " + num[4:6] + ", " + num[6:8] + ", " + num[8:10] + ", " + num[10:12]
	        return _str
	    _str = "0" + num[0:1] + ", " + num[1:3] + ", " + num[3:5] + ", " + num[5:7] + ", " + num[7:9]
	    return _str

	def getUnum(self):
	    num = self._proche_profil['phone']
	    if (num == None):
	    	return "118, 218"
	    if (num[0:3] == '+33'):
	        _str = "0" + num[3:4] + ", " + num[4:6] + ", " + num[6:8] + ", " + num[8:10] + ", " + num[10:12]
	        return _str
	    _str = "0" + num[0:1] + ", " + num[1:3] + ", " + num[3:5] + ", " + num[5:7] + ", " + num[7:9]
	    return _str

	def getlevels(self):
	    levels = self._victime_profil['cursus_users'][0]['level']
	    return str(levels)

	def getPos(self):
	    actuel_loc = self._victime_location[0]['host']
	    if (self._victime_location[0]['end_at'] != None):
	    	return ", Ah, non je suis pas la enfaite"
	    etage = actuel_loc[1]
	    rangee = actuel_loc[actuel_loc.index('r') + 1:actuel_loc.index('p')]
	    pos = actuel_loc[actuel_loc.index('p') + 1:]
	    return " Etage " + str(etage) + ", rangeai " + str(rangee) + ", position " + str(pos)

	def getPrenom(self):
		return self._prenom;

	def getNom(self):
		return self._nom;

	def getDisplayName(self):
		return (self._prenom + " " + self._nom)

	def getUDisplayName(self):
		prenom = self.remove_accents(self._proche_profil['first_name'])
		nom = self.remove_accents(self._proche_profil['last_name'])
		return (prenom + " " + nom)

	#-------------------------- FIN FONCTIONS D'ANNILEMENT -----------------------#








