// whattotest.cpp

#include "whattotest.h"
 
WidgetWithArrays::WidgetWithArrays() : m_count(0)
{
    for (int i =0 ; i < 100; i++) 
    {
        m_array[i] = 0;
    }
}

 
void WidgetWithArrays::storeInteger(int a)
{
    //TODO:

}

int WidgetWithArrays::sum()
{
    int retVal = 0;
    // TODO:
    // hint standard for loop OR
    // try looking into range based for loop (hint it can work with dumb arrays)
    for (int n : m_array)
    {
        retVal += n;
    }

    return retVal;
}
 

WidgetWithVector::WidgetWithVector()
{


}

void WidgetWithVector::storeInteger(int a)
{
    m_vector.push_back(a);

}

int WidgetWithVector::sum()
{
    int retVal = 0;

    for(int n : m_vector)
    {
        retVal = retVal +n;
    }


    return retVal;
}
 


