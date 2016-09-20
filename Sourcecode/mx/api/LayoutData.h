// MusicXML Class Library v0.3.0
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once

#include "mx/api/MxApiCommon.h"

#include <string>
#include <vector>

namespace mx
{
    namespace api
    {
        
        // distance values are in 'tenths' governed by the 'scaling' values

        class LayoutData
        {
        public:

            long double scalingMillimeters;
            long double scalingTenths;

            inline long double tenthsPerMillimeter() const
            {
                return scalingTenths / scalingMillimeters;
            }

            inline long double tenthsPerInch() const
            {
                return tenthsPerMillimeter() * 25.4;
            }

            long double pageWidth;             // negative number represent the absence of a value
            long double pageHeight;            // negative number represent the absence of a value

            long double oddPageLeftMargin;     // negative number represent the absence of a value
            long double oddPageRightMargin;    // negative number represent the absence of a value
            long double oddPageTopMargin;      // negative number represent the absence of a value
            long double oddPageBottomMargin;   // negative number represent the absence of a value
            long double evenPageLeftMargin;    // negative number represent the absence of a value
            long double evenPageRightMargin;   // negative number represent the absence of a value
            long double evenPageTopMargin;     // negative number represent the absence of a value
            long double evenPageBottomMargin;  // negative number represent the absence of a value

            long double systemLeftMargin;      // negative number represent the absence of a value
            long double systemRightMargin;     // negative number represent the absence of a value
            long double systemDistance;        // distance from bollom line of one system to top line of next system, negative number represent the absence of a value
            long double topSystemDistance;     // first system distance from top margin to top line of first staff, negative number represent the absence of a value
            long double staffDistance;         // the space between staves within the same system, negative number represent the absence of a value

            LayoutData()
            : scalingMillimeters( 7.0 )
            , scalingTenths( 40.0 )
            , pageWidth( tenthsPerInch() * 8.5 ) // 8.5"
            , pageHeight( tenthsPerInch() * 11 ) // 11"
            , oddPageLeftMargin( -1.0 )
            , oddPageRightMargin( -1.0f )
            , oddPageTopMargin( -1.0f )
            , oddPageBottomMargin( -1.0f )
            , evenPageLeftMargin( -1.0f )
            , evenPageRightMargin( -1.0f )
            , evenPageTopMargin( -1.0f )
            , evenPageBottomMargin( -1.0f )
            , systemLeftMargin( -1.0f )
            , systemRightMargin( -1.0f )
            , systemDistance( -1.0f )
            , topSystemDistance( -1.0f )
            , staffDistance( -1.0f )
            {

            }


            inline bool areOddMarginsValid() const
            {
                return oddPageLeftMargin > 0
                    && oddPageRightMargin > 0
                    && oddPageTopMargin > 0
                    && oddPageBottomMargin > 0;
            }


            inline bool areEvenMarginsValid() const
            {
                return evenPageLeftMargin > 0
                    && evenPageRightMargin > 0
                    && evenPageTopMargin > 0
                    && evenPageBottomMargin > 0;
            }


            inline bool areOddEvenMarginsTheSame() const
            {
                return areSame(oddPageLeftMargin, evenPageLeftMargin)
                    && areSame(oddPageRightMargin, evenPageRightMargin)
                    && areSame(oddPageTopMargin, evenPageTopMargin)
                    && areSame(oddPageBottomMargin, evenPageBottomMargin);
            }

        };
    }
}
