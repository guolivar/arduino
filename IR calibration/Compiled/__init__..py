
# Magic this code allows us to drop any file into this folder and make them accessable by using from <foldername> import *
# eg: from Sensors import *
# according to http://www.google.com/url?q=http%3A%2F%2Fstackoverflow.com%2Fquestions%2F1057431%2Floading-all-modules-in-a-folder-in-python&sa=D&sntz=1&usg=AFQjCNEh3uuPzzdigt0ABNBB881ZuEMXxw

from os.path import dirname, basename, isfile
import glob
modules = glob.glob(dirname(__file__)+"/*.py")
__all__ = [ basename(f)[:-3] for f in modules if isfile(f)]