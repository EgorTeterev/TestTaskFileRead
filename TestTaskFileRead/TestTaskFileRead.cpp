#include "PCH.h"
#include "ArrayTransformFactory.h"
#include "Templates.h"

template<typename T>
class ArrayTransformer;

//enter your file path
#define ARRAYFILEPATH "ReadArrays.txt"


int main()
{
/* 
File ReadArrays.txt:
12516,1,16 15, 3 610,32,161, 21 491,2 204 161 2151 43 1964 129 4939 921 5312 312 22 11 521\r\n - first arr line
12,125,7,16 3 1234,634,1 124, 74 21 43 23 2 11 22 1 1 24, 21\r\n                               - second arr line
105,270,15 21 3165, 32,15 215 22 22, 3 ,43, 16(EOF)                                            - third arr line
*/

//"Функції маніпуляцій над масивами необхідно оформити через фабрику... абстрактний клас ArrayTransformer ..."
	ArrayTransformer<std::vector<int>>* SortTransformer = ArrayTransformFactory<std::vector<int>>::Create(TransformClasses::Sort);
	ArrayTransformer<std::vector<int>>* ReverseTransformer = ArrayTransformFactory<std::vector<int>>::Create(TransformClasses::Reverse);
	ArrayTransformer<std::vector<int>>* FindCollisionTransformer = ArrayTransformFactory<std::vector<int>>::Create(TransformClasses::FindCollision);


	std::ifstream Stream(ARRAYFILEPATH);
	std::vector<int> First, Second, Third;


//"Програма має вміти"
//"зчитувати масиви з файлу"
	FitFileLineToContainer<std::vector<int>, int>(Stream, First);
	FitFileLineToContainer<std::vector<int>, int>(Stream, Second, 2);
	FitFileLineToContainer<std::vector<int>, int>(Stream, Third, 3);



//"друкувати вміст масивів"
	FileReader::LogLineFromFile(Stream); // з файлу
	ConsoleCon(&First);                  // просто масив


//"сортувати масиви без допомоги вбудованих функцій"
	//ConsoleCon(&First);
	SortTransformer->Transform(First);
	//ConsoleCon(&First);



//"знаходити перетин масивів(двох з найбільшою довгою та всіх трьох)"
	std::vector<int>* CollisionResult = FindCollisionTransformer->TransformWithResult(First, Second, Third);

//"створювати відсортований у зворотному порядку масив, що містить лише унікальні елементи з трьох представлених масивів"
	ReverseTransformer->Transform(*CollisionResult);
	//ConsoleCon(CollisionResult);
}