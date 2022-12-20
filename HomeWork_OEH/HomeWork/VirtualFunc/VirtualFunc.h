#pragma once


class Parent
{

public:
	Parent();
	~Parent();

	virtual void ShowMyInfo();
	char name = 'c';
	int age = 10;

private:

};

class Child : public Parent
{

public:

	void ShowMyInfo() override;


	Child();
	~Child();

	Child(const Child& _Other) = delete;
	Child(Child&& _Other) noexcept = delete;
	Child& operator=(const Child& _Other) = delete;
	Child& operator=(Child&& _Other) noexcept = delete;

protected:

private:

};

