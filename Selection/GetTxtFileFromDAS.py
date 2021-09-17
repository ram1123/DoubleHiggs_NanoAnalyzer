import os


InputFileFromWhereReadDASNames = '/afs/cern.ch/user/r/rasharma/work/doubleHiggs/ResonantAnalysis/nanoAODSetup/CMSSW_10_6_20/src/PhysicsTools/NanoAODTools/python/postprocessing/analysis/nanoAOD_vvVBS/input_data_Files/HH_sample_list_v7_2017_campaign.txt'

with open(InputFileFromWhereReadDASNames) as in_file:
    for lines in in_file:
        if not lines.startswith("#"):
            print lines
            sample_name = lines.split('/')[1]
            campaign = lines.split('/')[2].split('-')[0]
            print "==> sample_name = ", sample_name
            print "==> campaign = ", campaign
            outjdl_file = open(sample_name + ".txt", "w")
            xrd_redirector = 'root://cms-xrd-global.cern.ch/'
            output = os.popen('dasgoclient --query="file dataset=' + lines.strip() + '"').read()
            for root_file in output.split():
                # outjdl_file.write((xrd_redirector + root_file).replace('/', '\/'))
                outjdl_file.write(xrd_redirector + root_file + '\n')
            outjdl_file.close()
