#pragma once

class Card

{

	public:
		Card(int value, int suit);
		Card() = delete; // no default constructor
		virtual ~Card() ;

		Card( const Card &c); // Copy constructor
		Card& operator=(const Card& c); // assignment operator

		int GetValue() const ;
		int GetSuit() const ;
		int GetGuid() const ;

		Card(Card && obj) noexcept; // Move constructor
		Card& operator=(Card&& obj) noexcept; // Move assignment operator


	private:
		int m_value;
		int m_suit;
		int m_guid;
		

};