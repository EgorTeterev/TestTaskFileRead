#pragma once
#include "ArrayTransformer.h"

template<typename Elem>
class HoarSortTransform : public ArrayTransformer<Elem>
{
public:
	virtual void Transform(std::vector<Elem>& Array) override;
};

//"��������� ������ ��� �������� ���������� �������". ����������� �������?
template<typename Elem>
void HoarSortTransform<Elem>::Transform(std::vector<Elem>& Array)
{
	return;
}