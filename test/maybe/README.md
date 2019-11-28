

```bash
mkdir -p build
g++ -I../../include -I../../test/include  -lgtest -lpthread -L../Debug64  test-main.cc -o build/test-main -g -std=c++17 -fmax-errors=1
build/test-main
bl
-------------------
false false
-------------------
bl
mv
-------------------
true true
-------------------
bl
-------------------
cp
true true
mv
true true
false false
bl
bl
-------------------
cp
false true
mv
false true
-----------main3--------
bl
mv
-------------------
mv
cp
1
-------------------
cp
1
-------------------
mv
1
-------------------
-----------main4--------
bl
mv
-------------------
cp
cp
1
-------------------
cp
1
-------------------
cp
1

```