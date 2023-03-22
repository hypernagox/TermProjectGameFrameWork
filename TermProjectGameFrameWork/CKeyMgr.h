#pragma once

enum class KEY_STATE
{
	NONE,	
	TAP, 
	HOLD, 
	AWAY, 
};

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	W,
	A,
	S,
	D,
	SPACE,
	ENTER, 
	TAB,
	LBTN,	
	RBTN,	
	LSHIFT, 
	CTRL, 
	RSHIFT,
	LAST,		

};

struct tKeyInfo
{
	KEY_STATE		eState;		// 키의 상태를 알려주는 enum 값
	bool			bPrevPush;			// 이전에 눌렸는지 안눌렸는지
};

class CKeyMgr
	:public Singleton<CKeyMgr>
{
	friend class Singleton;
	CKeyMgr();
public:
	~CKeyMgr();
private:
	vector<tKeyInfo>m_vecKey;			
	Vec2			m_vCurMousePos = {};	
public:
	void init();
	void update();
public:
	KEY_STATE GetKeyState(KEY _eKey) { return m_vecKey[(int)_eKey].eState; }
	Vec2	GetMousePos()const { return m_vCurMousePos; }	
};
