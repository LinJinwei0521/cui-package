apt install libcurl
wget https://raw.githubusercontent.com/LinJinwei0521/cuou-package/refs/heads/main/cget-package/Cget.c
gcc -o cget cget.c -lcurl
rm cget.c
rm Packageinstall.sh
