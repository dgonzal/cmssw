#ifndef HADSHOWERMATERIAL_H
#define HADSHOWERMATERIAL_H

namespace hadshower{

    class Material{

	public:

	enum MaterialType { ECAL,GAP,HCAL };

	Material(MaterialType type,double dz,double cmPerIntLen,double radLenPerIntLen) 
	    : type(type)
	    , dz(dz)
	    , cmPerIntLen(cmPerIntLen)
	    , radLenPerIntLen(radLenPerIntLen)
	{;}
	
	const MaterialType type;
	const double dz;
	const double cmPerIntLen;
	const double radLenPerIntLen;

    };

}

#endif
