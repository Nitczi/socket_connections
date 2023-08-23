# Explanation
This script will repeatedly open connections to a specific port on a target host and will not close them. As long as the condition 'while 1 is equal to 1' holds true, this script will continue to run, causing a Denial of Service (DoS) attack.

If the second argument is not passed, the script will run the DoS attack on port 21 by default.
