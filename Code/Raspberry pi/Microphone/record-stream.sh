
#!/bin/bash
arecord -l && arecord -D hw:1 -c2 -r 48000 -f S32_LE | python record.py