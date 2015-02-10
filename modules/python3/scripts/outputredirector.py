import sys
import inviwo_internal

class OutputRedirectStdout:
    def write(self, string):
        inviwo_internal.ivwPrint(string, 0)

class OutputRedirectStderr:
    def write(self, string):
        inviwo_internal.ivwPrint(string, 1)

sys.stdout = OutputRedirectStdout()  
sys.stderr = OutputRedirectStderr() 

