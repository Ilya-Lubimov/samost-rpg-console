// Пропишу статы сам. Если будут какие-нибудь идеи насчёт этого,
// то пиши их в комментарии:
/*



*/
class Being{
private:
	int id;
public:
	static int count;

	void GetId(){
		return id;
	}

	Being(){
		++count;
		id = count;
	}
};

int Being::count = 0;