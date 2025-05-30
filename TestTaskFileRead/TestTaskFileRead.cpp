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
"Буде дано текстовий файл, де в рядок буде задекларовано три масиви цілих чисел.
Кожен масив описується окремим рядком числа розділені або пробілом, або комою,
або двома символами одночасно".

File ReadArrays.txt:
12516,1,16 15, 3 610,32,161, 21 491,2 204 161 2151 43 1964 129 4939 921 5312 312 22 11 521\r\n - first arr line
12,125,7,16 3 1234,634,1 124, 74 21 43 23 2 11 22 1 1 24, 21\r\n                               - second arr line
105,270,15 21 3165, 32,15 215 22 22, 3 ,43, 16(EOF)                                            - third arr line

*/

	std::ifstream Stream(ARRAYFILEPATH);
	std::vector<int> First,Second,Third;

	FitFileLineToContainer<std::vector<int>,int>(Stream, First);
	FitFileLineToContainer<std::vector<int>, int>(Stream, Second,2);
	FitFileLineToContainer<std::vector<int>, int>(Stream, Third, 3);


	ArrayTransformer<std::vector<int>>* Transformer = ArrayTransformFactory<std::vector<int>>::Create(TransformClasses::FindCollision);

	std::vector<int>* CollisionResult = Transformer->TransformWithResult(Second, First,Third);
	//ConsoleCon(CollisionResult);


}