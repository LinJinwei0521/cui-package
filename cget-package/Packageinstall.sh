apt install libcurl
wget https://raw.githubusercontent.com/LinJinwei0521/cuou-package/refs/heads/main/cget-package/Cget.c
wget https://raw.githubusercontent.com/LinJinwei0521/cuou-package/refs/heads/main/cget-package/cuoupackage.cpc
gcc -o cget Cget.c -lcurl
rm Cget.c
rm Packageinstall.sh
