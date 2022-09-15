//#include "TV.h"
//
//void TV::OnOff()
//{
//	this->isOn = !this->isOn;
//}
//
//void TV::VolumeUp()
//{
//	if (this->Volume < this->maxVol)
//		this->Volume += 1;
//	else
//		return;
//}
//
//void TV::VolumeDown()
//{
//	if (this->Volume > this->minVol)
//		this->Volume -= 1;
//	else
//		return;
//}
//
//void TV::ChannelUp()
//{
//	if (this->channel < this->maxChannel)
//		this->channel += 1;
//	else
//		return;
//}
//
//void TV::ChannelDown()
//{
//	if (this->channel > this->minChannel)
//		this->channel -= 1;
//	else
//		return;
//}
//
//int TV::GetChannel()
//{
//	return this->channel;
//}
//
//int TV::GetVolume()
//{
//	return this->Volume;
//}
//
//bool TV::GetState()
//{
//	return this->isOn;
//}
//
//TV::TV():isOn(false), channel(1), Volume(50) {}
//TV::TV(const TV& tv)
//{
//	this->isOn = tv.isOn;
//	this->channel = tv.channel;
//	this->Volume = tv.Volume;
//}
//TV::~TV()
//{
//	// nothing to do
//}
