import json
import urllib2
import urllib
import sys


def getAccessToken():
	payload = {'grant_type': "client_credentials", 'client_id': "958a4e6644dd5787e9e23644f0c4314586147968d34c83b6974193d6f0dabdd4", 'client_secret': "223b3aef0dc7f228f1d47193f8d244d8f5eb42a25981347aadcab7e1dcfb6d5b"}
	req = urllib2.Request("https://api.intra.42.fr/oauth/token", data=urllib.urlencode(payload))
	response = urllib2.urlopen(req).read()
	fjson = json.loads(response)
	return fjson["access_token"]



def getResponseJson(url):
	req = urllib2.Request(url)
	req.add_header('Authorization', 'Bearer '+ TOKEN)
	resp = urllib2.urlopen(req).read()
	return json.loads(resp)


UserName = sys.argv[1]
TOKEN = getAccessToken()
vals = getResponseJson('https://api.intra.42.fr/v2/users/'+UserName)

userid = vals['campus_users'][0]['user_id']

"""
nbProjects = len(vals['projects_users'])
for i in range(nbProjects):
	print vals['projects_users'][i]['project']['name'] +  " : " + vals['projects_users'][i]['status'] + " -> " + str(vals['projects_users'][i]['final_mark']) + "%"
"""
"""

nbProjects = len(vals['projects_users'])
somme = 0
nb = 0
for i in range(nbProjects):
	if (vals['projects_users'][i]['status'] == 'finished'):
		if (vals['projects_users'][i]['project']['name'][10:14] == 'Exam'):
			nb += 4
			somme += 4 * vals['projects_users'][i]['final_mark']
		else:
			nb += 1
			somme += vals['projects_users'][i]['final_mark']
		
print (somme / nb)
"""

val2 = getResponseJson('https://api.intra.42.fr/v2/feedbacks?filter[user_id]=' + str(userid) + "&sort=-created_at")
nbfeedb = len(val2)
for i in range(nbfeedb):
	print (val2[i]['comment'])