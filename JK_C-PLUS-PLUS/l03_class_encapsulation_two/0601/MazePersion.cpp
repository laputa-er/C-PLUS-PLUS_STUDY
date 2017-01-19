#include "MazePerson.h"
#include "MazeMap.h"

MazePerson::MazePerson():personPic('*')
{
	positionX = 1;
	positionY = 5;
	preX = 10000;
	preY = 10000;
	personSpeed = 10000;
	forward = NORTH;
	outOrNot = false;
}

MazePerson::MazePerson(int currentX, int currentY):personPic('*')
{
	positionX = currentX;
	positionY = currentY;
	preX = 10000;
	preY = 10000;
	forward = NORTH;
	outOrNot = false;
}

MazePerson::MazePerson(int currentX, int currentY, objectiveDirections myForward):personPic('*')
{
	positionX = currentX;
	positionY = currentY;
	preX = 10000;
	preY = 10000;
	forward = myForward;
	outOrNo = false;
}

void MazePerson::savePrePosition()
{
	preX = positionX;
	preY = positionY;
}

void MazePerson::moveSouth()
{
	// 将前一个位置赋值为当前位置
	savePrePosition();
	// 向南移动一个位置
	positionX = positionX;
	positionY = positionY + 1;
}

void MazePerson::moveNorth()
{
	savePrePosition();
	positionX = positionX;
	positionY = positionY - 1;
}

void MazePerson::maveWest()
{
	savePrePosition();
	positionX = positionX -1;
	positionY = positionY;
}

void MazePerson::moveEast()
{
	savePrePosition();
	positionX = positionX + 1;
	positionY = positionY;
}

void MozePerson::gotoxy(int x, int y)
{
	COORD cd;
	cd.x = x;
	cd.y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

void MazePerson::drawPerson()
{
	// 获取迷宫通道字符
	char mazeRoad = MazeMap::getRoadChar();
	// 将光标移动到上一个位置
	gotoxy(preX, preY);
	// 绘制通道
	cout << mazeRoad;
	// 将光标移动到当前位置
	gotoxy(positionX, positionY);
	// 绘制人
	cout << personPic;
	// 为制作动画效果使用时间延迟
	Sleep(personSpeed);
}

MazePerson &MazePerson::serPersonPosition(int coordinateX, int coordinateY)
{
	positionX = coordinateX;
	positionY = coordinateY;
	return *this;
}

void MazePerson::setPersonPos(int coordX, int coordY)
{
	positionX = coordX;
	positionY = coordY;
}

MazePerson &MazePerson::setPersonChar(char personChar)
{
	personPic = personChar;
	return *this;
}

void MazePerson::setPersonPic(char personChar)
{
	personPic = personChar;
}

MazePerson &MazePerson::setPersonForward(objectiveDirections myForward)
{
	forward = myForward;
	return *this;
}

void MazePerson::setPersonForwardDirection(objectiveDirections myForward)
{
	forward = myForward;
}

void MazePerson::turnLeft()
{
	switch(forward)
	{
		case NORTH:
			forward = WEST;
			break;
		case WEST:
			forward = SOUTH;
			break;
		case SOUTH:
			forward = EAST;
			break;
		case EAST:
			forward = NORTH;
			break;
		default:
			cout << "方向错误。" << endl;
	}
}

void MazePerson::turnRight()
{
	switch(forward)
	{
		case NORTH:
			forward = EAST;
			break;
		case WEST:
			forward = NORTH;
			break;
		case SOUTH:
			forward = WEST;
			break;
		case EAST:
			forward = SOUTH;
			break;
		default:
			cout << "方向错误" << endl;
	}
}

void MazePerson::geAhead()
{
	switch(forward)
	{
		case NORTH:
			moveNorth();
			break;
		case WEST:
			moveWest();
			break;
		case SOUTH:
			moveSouth();
			break;
		case EAST:
			moveEast();
			break;
		default:
			cout << "方向不明，无法前进。" << endl;
	}
	// 形成动画
	drawPerson();
	// 检测是否到达出口
	if (MazeMap::checkMazeDoor(positionX, positionY))
	{
		gotoxy(0, 22);
		cout << "哈哈，终于出来啦！" << endl;
		outOrNo = true;
	}
}

void MazePerson::setPersonSpeed(int speed)
{
	// 设置一个时间延迟的值
	personSpeed = speed * 500;
}

void MazePerson::setPersonSpeed(long speed)
{
	// 设置一个时间延迟的值
	personSpeed = speed;
}

void MazePerson::start()
{
	int i = 0;
	while (!outOrNo)
	{
		gotoxy(0, 15);
		cout << i;
		i++;
		moveForward();
	}
}

bool MazePerson::moveForward()
{
	if (MazeMap::checkWallOrNot(positionX, positionY)) {
		// 检测到当前位置是墙，提示用户设计非法并返回
		gotoxy(0, 23);
		cout << "检测到当前设定的起始位置是墙壁，情重新设定。" << endl;
		outOrNot = true;
		return NO;
	}
	// 判断如果前一个位置的坐标是 10000,说明是第一步，则直接在当前位置绘制人
	if (preX == 10000 || preY == 10000)
	{
		gotoxy(positionX, positionY);
		cout << personPic;
		Sleep(5000);
	}
	// 根据当前坐标和方向，确定右侧位置和前方位置的坐标
	int rightX;
	int rightY;

	int forwardX;
	int forwardY;

	switch(forward)
	{
		case SOUTH:
			rightX = positionX - 1;
			rightY = positionY;
			forwardX = positionX;
			forwardY = positionY + 1;
			break;
		case NORTH:
			rightX = positionX + 1;
			rightY = positionY;
			forwardX = positionX;
			forwardY = positionY - 1;
			break;
		case WEST:
			rightX = positionX;
			rightY = positionY - 1;
			forwardX = positionX - 1;
			forwardY = positionY;
			break;
		case EAST:
			rightX = positionX;
			rightY = positionY + 1;
			forwardX = positionX + 1;
			forwardY = positionY;
			break;
	}

	/*
	* 检查右侧是否是墙，如果是墙，检查前方是否是墙；如果不是墙则前进，前进后检查是否是出口
	*/
	// 如果右侧是墙
	if(MazeMap::checkWallOrNot(rightX, rightY))
	{
		// 如果前方也是墙
		if(MazeMap::checkWallOrNot(forwardX, forwardY))
		{
			// 按逆时针转换一个方向
			turnLeft();
			return NO;
		}
		// 前方(仍然)是通道
		else
		{
			// 向前一栋
			goAhead();
			return YES;
		}
	}
	// 如果右侧是通路
	else
	{
		Sleep(3000);
		turnRight();
		goAhead();
		return YES;
	}
}