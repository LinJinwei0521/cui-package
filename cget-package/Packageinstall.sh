apt install libcurl
wget https://github.com/LinJinwei0521/cuou-package/blob/main/cget-package/cget.c
gcc -o cget cget.c -lcurl
rm cget.c
