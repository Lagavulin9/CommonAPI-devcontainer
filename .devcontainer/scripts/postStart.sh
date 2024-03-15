# Routines for postStart

# git configuration
git config --global --add safe.directory .

# Create a symbolic link for .ini
if [ -f "conf/commonapi.ini" ]; then
    export COMMONAPI_CONFIG=$(pwd)/conf/commonapi.ini
    echo "Using user configuration /conf/commonapi.ini."
else
    echo "Using image default /etc/commonapi.ini."
fi
