#include "StdAfx.h"
#include "ObjectMananger.h"

CObjectMananger::CObjectMananger(void)
{
	resetObjectList();
}

CObjectMananger::~CObjectMananger(void)
{
	resetObjectList();
}

void CObjectMananger::resetObjectList()
{
	m_ObjectList.clear();

	//dhPrint("��ü ����Ʈ�� �ʱ�ȭ �մϴ�. ��ü����Ʈ ������[%d]..!!!\n", GetSize());
}

void CObjectMananger::addObject(CObjectBase object)
{
	int i, count = GetSize();
	for( i=0 ; i<count ; i++ )
	{
		if(object.getObjectID() == m_ObjectList[i].getObjectID())
		{
			//dhPrint("��ü ����Ʈ�� �̹� �����ϴ� ID[%d]�� ��ü ���� �޽����� ���ŵǾ���..!!!\n", object.getObjectID());
			return;
		}			
	}

	m_ObjectList.push_back(object);
	//dhPrint("��ü ����Ʈ�� ID[%d] �� ��ü������ �߰��Ͽ���...!!!\n", object.getObjectID());

	return;
	
}


void CObjectMananger::delObject(int objectID)
{
	std::vector<CObjectBase>::iterator itor;
	for( itor=m_ObjectList.begin();itor !=m_ObjectList.end() ;itor++)
	{
		CObjectBase objectData = *itor;
		if( objectID == objectData.getObjectID() )
		{
			m_ObjectList.erase(itor);
			//dhPrint("�ش��ϴ� ��ü����[%d]�� ��ü����Ʈ���� �����մϴ�. !!\n",objectID);

			return;
		}
	}

	//dhPrint("�ش��ϴ� ID[%d]�� ��ġ�ϴ� ��ü������ �����ϴ�. !!\n",objectID);
}

void CObjectMananger::updateObject(CObjectBase object)
{
	int i, count = GetSize();
	for( i=0 ; i<count ; i++ )
	{
		if(object.getObjectID() == m_ObjectList[i].getObjectID())
		{
			m_ObjectList[i].setObjectType(object.getObjectType());

			m_ObjectList[i].setTimeStamp(object.getTimeStamp());
			m_ObjectList[i].setIFF(object.getIFF());
			m_ObjectList[i].setObjectStatus(object.getObjectStatus());

			double x, y, z;
			double h, p, r;

			object.getInitPosition(x, y, z);
			object.getInitDirection(h, p, r);

			m_ObjectList[i].setInitPosition(x, y, z);
			m_ObjectList[i].setInitDirection(h, p, r);

			object.getTranslate(x, y, z);
			object.getRotate(h, p, r);

			m_ObjectList[i].setTranslate(x, y, z);
			m_ObjectList[i].setRotate(h, p, r);
			
			return;
		}			
	}
	//dhPrint("��ü ����Ʈ�� ������ ID[%d]�� ��ü������ ����....!!!\n", object.getObjectID());
}

void CObjectMananger::updateObject(int objectID, double x, double y, double z)
{
	int i, count = GetSize();
	for( i=0 ; i<count ; i++ )
	{
		if(objectID == m_ObjectList[i].getObjectID())
		{
			m_ObjectList[i].setTranslate(x, y, z);

			return;
		}			
	}
	//dhPrint("��ü ����Ʈ�� ������ ID[%d]�� ��ü������ ����....!!!\n", objectID);
}

void CObjectMananger::updateObject(int objectID, double x, double y, double z, double h, double p, double r)
{
	int i, count = GetSize();
	for( i=0 ; i<count ; i++ )
	{
		if(objectID == m_ObjectList[i].getObjectID())
		{
			m_ObjectList[i].setTranslate(x, y, z);
			m_ObjectList[i].setRotate(h, p, r);

			return;
		}			
	}
	//dhPrint("��ü ����Ʈ�� ������ ID[%d]�� ��ü������ ����....!!!\n", objectID);
}

void CObjectMananger::updateObject(int objectID, double dIncreaseHeading, double dVelocity)
{
	int i, count = GetSize();
	for( i=0 ; i<count ; i++ )
	{
		if(objectID == m_ObjectList[i].getObjectID())
		{
			m_ObjectList[i].setIncreaseH(dIncreaseHeading);
			m_ObjectList[i].setIncreaseVel(dVelocity);

			return;
		}			
	}
	//dhPrint("��ü ����Ʈ�� ������ ID[%d]�� ��ü������ ����....!!!\n", objectID);
}

void CObjectMananger::updateObjectVel(int objectID, double dVelocity)
{
	int i, count = GetSize();
	for( i=0 ; i<count ; i++ )
	{
		if(objectID == m_ObjectList[i].getObjectID())
		{
			m_ObjectList[i].setIncreaseVel(dVelocity);

			return;
		}			
	}
	//dhPrint("��ü ����Ʈ�� ������ ID[%d]�� ��ü������ ����....!!!\n", objectID);
}

void CObjectMananger::updateObjectAVel(int objectID, double dIncreaseHeading)
{
	int i, count = GetSize();
	for( i=0 ; i<count ; i++ )
	{
		if(objectID == m_ObjectList[i].getObjectID())
		{
			m_ObjectList[i].setIncreaseH(dIncreaseHeading);

			return;
		}			
	}
	//dhPrint("��ü ����Ʈ�� ������ ID[%d]�� ��ü������ ����....!!!\n", objectID);
}

void CObjectMananger::updateObjectDVel(int objectID, double dIncreaseDepth)
{
	int i, count = GetSize();
	for( i=0 ; i<count ; i++ )
	{
		if(objectID == m_ObjectList[i].getObjectID())
		{
			m_ObjectList[i].setIncreaseDepth(dIncreaseDepth);

			return;
		}			
	}
	//dhPrint("��ü ����Ʈ�� ������ ID[%d]�� ��ü������ ����....!!!\n", objectID);
}

CObjectBase* CObjectMananger::GetObjectPointer(int objectID)
{
	int i, count = GetSize();
	for( i=0 ; i<count ; i++ )
	{
		if(objectID == m_ObjectList[i].getObjectID())
		{
			return &(CObjectBase)m_ObjectList[i];
		}			
	}
	//dhPrint("��ü ����Ʈ�� ������ ID[%d]�� ��ü������ ����....!!!\n", objectID);

	return NULL;
}

CObjectBase* CObjectMananger::GetObjectPointerIdx(int index)
{
	int count = GetSize();

	if(index >= count)
	{
		//dhPrint("��ü ����Ʈ�� ������ index[%d]�� ��ü������ ����....!!!\n", index);
		return NULL;
	}

	return &(CObjectBase)m_ObjectList[index];
}

bool CObjectMananger::checkObjectID(int objectID)
{
	int i, count = GetSize();
	for( i=0 ; i<count ; i++ )
	{
		if(objectID == m_ObjectList[i].getObjectID())
		{
			return true;
		}			
	}
	return false;

}