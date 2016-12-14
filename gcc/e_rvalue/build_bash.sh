# ./build bash (filename)
cppfile="$1.cpp"
name="$1"
echo Build file "$cppfile"
echo output name "$name"
g++ "$cppfile" -o "$name" -std=c++11
