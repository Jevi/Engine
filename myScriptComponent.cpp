#include "myScriptComponent.h"

myScriptComponent::myScriptComponent(std::string Id, std::string Filename, bool Enabled) :
		myComponent(Id, myComponent::SCRIPT), filename(Filename) {
	enabled = Enabled;
}

myScriptComponent::~myScriptComponent(void) {

}

void myScriptComponent::Start() {

}

void myScriptComponent::Update(unsigned long dt) {

}

std::string myScriptComponent::ToString() {
	return "SCRIPT";
}