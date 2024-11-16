apt install libcurl
wget https://github.com/LinJinwei0521/cuou-package/raw/refs/heads/main/cget-package/Cget.c
gcc -o cget cget.c -lcurl
rm cget.c
rm Packageinstall.sh
