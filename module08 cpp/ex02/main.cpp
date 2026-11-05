#include "MutantStack.hpp"

int main()
{
	std::cout << "--- subject ---" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "--- list ---" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << "--- strings ---" << std::endl;
	MutantStack<std::string> str;
	str.push("one");
	str.push("two");
	str.push("three");
	for (MutantStack<std::string>::iterator sit = str.begin(); sit != str.end(); ++sit)
		std::cout << *sit << std::endl;


	std::cout << "--- empty ---" << std::endl;
	MutantStack<int> empty;
	if (empty.begin() == empty.end())
		std::cout << "empty: ok" << std::endl;


	std::cout << "--- const ---" << std::endl;
	const MutantStack<int> cs(mstack);
	for (MutantStack<int>::const_iterator cit = cs.begin(); cit != cs.end(); ++cit)
		std::cout << *cit << " ";
	std::cout << std::endl;


	std::cout << "--- reverse ---" << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;

	std::cout << "--- copy ---" << std::endl;
	MutantStack<int> a;
	a.push(1);
	a.push(2);
	MutantStack<int> b(a);
	a.push(3);
	std::cout << a.size() << " " << b.size() << std::endl;

	return 0;
}