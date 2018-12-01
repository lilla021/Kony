#include "Tokens.h"

Tokens::Tokens()
{
}
Tokens::~Tokens()
{
}
std::string Tokens::getTokenName() {
	return name;
}
Web::Web() {
	tokTotal = 13;
	name = "Web";
}
Web::~Web() {}

Jinx::Jinx() {
	tokTotal = 13;
	name = "Jinx";
}
Jinx::~Jinx() {}
Souvenir::Souvenir() {
	tokTotal = 5;
	name = "Souvenir";
}
Souvenir::~Souvenir() {}
Carapace::Carapace() {
	tokTotal = 15;
	name = "Carapace";
}
Carapace::~Carapace() {}

