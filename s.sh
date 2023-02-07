RED="\033[31m"
GREEN="\033[32m"
NORMAL=$(tput sgr0)


sed -i.bak 's/ ft::vector/ std::vector/g' vector.cpp
make re> /dev/null
./ft_containers > std

echo "your container tooks " 
time ./ft_containers > /dev/null
echo 

sed -i.bak 's/ std::vector/ ft::vector/g' vector.cpp
make re > /dev/null
./ft_containers > ft

echo "STL container tooks " 
time ./ft_containers > /dev/null

SUCCESS=$(diff std ft | wc -c)

make fclean > /dev/null


if [ $SUCCESS == 0 ]; then
    printf    "$GREEN%s""\033[1m[SUCCESS]\033[0m    ${NORMAL}\n"$RESET
    rm -f ft std
else
    printf    "$RED%s""\033[1m[FAILLURE]\033[0m    ${NORMAL}\n"$RESET
fi