#include <Alembic/Abc/All.h>
#include <Alembic/AbcGeom/All.h>
#include <Alembic/AbcCoreOgawa/All.h>

#define BOOLS_24 {true, false, true, false,\
                  true, false, true, false,\
                  true, false, true, false,\
                  true, false, true, false,\
                  true, false, true, false,\
                  true, false, true, false}
#define NUMERICS_24 {0, 1, 2, 3,\
                     4, 5, 6, 7,\
                     8, 9, 10, 11,\
                     12, 13, 14, 15,\
                     16, 17, 18, 19,\
                     20, 21, 22, 23}
#define STRING_24 {"hello", "world", "goodbye", "night",\
                   "hello", "world", "goodbye", "night",\
                   "hello", "world", "goodbye", "night",\
                   "hello", "world", "goodbye", "night",\
                   "hello", "world", "goodbye", "night",\
                   "hello", "world", "goodbye", "night"}

// python
// ', '.join(['{%i,%i}'%(x,x+1) for x in range(0,2*24,2)])
#define NUMERICS2_24 {{0,1}, {2,3}, {4,5}, {6,7},\
                      {8,9}, {10,11}, {12,13}, {14,15},\
                      {16,17}, {18,19}, {20,21}, {22,23},\
                      {24,25}, {26,27}, {28,29}, {30,31},\
                      {32,33}, {34,35}, {36,37}, {38,39},\
                      {40,41}, {42,43}, {44,45}, {46,47}}

#define NUMERICS3_24 {{0,1,2}, {3,4,5}, {6,7,8}, {9,10,11},\
                      {12,13,14}, {15,16,17}, {18,19,20}, {21,22,23},\
                      {24,25,26}, {27,28,29}, {30,31,32}, {33,34,35},\
                      {36,37,38}, {39,40,41}, {42,43,44}, {45,46,47},\
                      {48,49,50}, {51,52,53}, {54,55,56}, {57,58,59},\
                      {60,61,62}, {63,64,65}, {66,67,68}, {69,70,71}}

#define NUMERICS4_24 {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}, {12,13,14,15},\
                      {16,17,18,19}, {20,21,22,23}, {24,25,26,27}, {28,29,30,31},\
                      {32,33,34,35}, {36,37,38,39}, {40,41,42,43}, {44,45,46,47},\
                      {48,49,50,51}, {52,53,54,55}, {56,57,58,59}, {60,61,62,63},\
                      {64,65,66,67}, {68,69,70,71}, {72,73,74,75}, {76,77,78,79},\
                      {80,81,82,83}, {84,85,86,87}, {88,89,90,91}, {92,93,94,95}}

#define BOX2_24 {{{-1,-1},{1,1}}, {{-2,-2},{2,2}}, {{-3,-3},{3,3}}, {{-4,-4},{4,4}},\
                 {{-5,-5},{5,5}}, {{-6,-6},{6,6}}, {{-7,-7},{7,7}}, {{-8,-8},{8,8}},\
                 {{-9,-9},{9,9}}, {{-10,-10},{10,10}}, {{-11,-11},{11,11}}, {{-12,-12},{12,12}},\
                 {{-13,-13},{13,13}}, {{-14,-14},{14,14}}, {{-15,-15},{15,15}}, {{-16,-16},{16,16}},\
                 {{-17,-17},{17,17}}, {{-18,-18},{18,18}}, {{-19,-19},{19,19}}, {{-20,-20},{20,20}},\
                 {{-21,-21},{21,21}}, {{-22,-22},{22,22}}, {{-23,-23},{23,23}}, {{-24,-24},{24,24}}}


#define BOX3_24 {{{-1,-1,-1},{1,1,1}}, {{-2,-2,-2},{2,2,2}}, {{-3,-3,-3},{3,3,3}}, {{-4,-4,-4},{4,4,4}},\
                 {{-5,-5,-5},{5,5,5}}, {{-6,-6,-6},{6,6,6}}, {{-7,-7,-7},{7,7,7}}, {{-8,-8,-8},{8,8,8}},\
                 {{-9,-9,-9},{9,9,9}}, {{-10,-10,-10},{10,10,10}}, {{-11,-11,-11},{11,11,11}}, {{-12,-12,-12},{12,12,12}},\
                 {{-13,-13,-13},{13,13,13}}, {{-14,-14,-14},{14,14,14}}, {{-15,-15,-15},{15,15,15}}, {{-16,-16,-16},{16,16,16}},\
                 {{-17,-17,-17},{17,17,17}}, {{-18,-18,-18},{18,18,18}}, {{-19,-19,-19},{19,19,19}}, {{-20,-20,-20},{20,20,20}},\
                 {{-21,-21,-21},{21,21,21}}, {{-22,-22,-22},{22,22,22}}, {{-23,-23,-23},{23,23,23}}, {{-24,-24,-24},{24,24,24}}}

#define NUM_VERTS 8
#define BOX_VERTS  { {-1.0f, -1.0f, -1.0f},\
                     { 1.0f, -1.0f, -1.0f},\
                     {-1.0f, 1.0f, -1.0f},\
                     { 1.0f, 1.0f, -1.0f},\
                     {-1.0f, -1.0f, 1.0f},\
                     { 1.0f, -1.0f, 1.0f},\
                     {-1.0f, 1.0f, 1.0f},\
                     { 1.0f, 1.0f, 1.0f} }

#define NUM_FACES 6
#define BOX_FACES {4, 4, 4, 4, 4, 4}

#define NUM_INDICES 24
#define BOX_INDICES {\
                    0, 4, 6, 2,\
                    5, 1, 3, 7,\
                    0, 1, 5, 4,\
                    6, 7, 3, 2,\
                    1, 0, 2, 3,\
                    4, 5, 7, 6 }


using namespace Alembic::AbcGeom;

void add_props(OCompoundProperty &parent_prop, const std::string prefix) {
        
    OBoolProperty bool_prop(parent_prop, prefix + "_bool");
    bool_prop.set(true);
    OUcharProperty uchar_prop(parent_prop, prefix + "_uchar");
    uchar_prop.set(1);
    OCharProperty char_prop(parent_prop, prefix + "_char");
    char_prop.set(1);
    OUInt16Property uint16_prop(parent_prop, prefix + "_uint16");
    uint16_prop.set(1);
    OInt16Property int16_prop(parent_prop, prefix + "_int16");
    int16_prop.set(1);
    OUInt32Property uint32_prop(parent_prop, prefix + "_uint32");
    uint32_prop.set(1);
    OInt32Property int32_prop(parent_prop, prefix + "_int32");
    int32_prop.set(1);
    OUInt64Property uint64_prop(parent_prop, prefix + "_uint64");
    uint64_prop.set(1);
    OInt64Property int64_prop(parent_prop, prefix + "_int64");
    int64_prop.set(1);
    OHalfProperty float16_prop(parent_prop, prefix + "_float16");
    float16_prop.set(1.0f);
    OFloatProperty float32_prop(parent_prop, prefix + "_float32");
    float32_prop.set(1.0f);
    ODoubleProperty float64_prop(parent_prop, prefix + "_float64");
    float64_prop.set(1.0);
    OStringProperty string_prop(parent_prop, prefix + "_string");
    string_prop.set("shrug");
    OWstringProperty wstring_prop(parent_prop, prefix + "_wstring");
    wstring_prop.set(Alembic::Util::wstring(L"¯\\_(ツ)_/¯"));

    OV2sProperty v2s_prop(parent_prop, prefix + "_v2s");
    v2s_prop.set({1, 2});
    OV2iProperty v2i_prop(parent_prop, prefix + "_v2i");
    v2i_prop.set({1, 2});
    OV2fProperty v2f_prop(parent_prop, prefix + "_v2f");
    v2f_prop.set({1.0f, 2.0f});
    OV2dProperty v2d_prop(parent_prop, prefix + "_v2d");
    v2d_prop.set({1.0, 2.0});

    OV3sProperty v3s_prop(parent_prop, prefix + "_v3s");
    v3s_prop.set({1, 2, 3});
    OV3iProperty v3i_prop(parent_prop, prefix + "_v3i");
    v3i_prop.set({1, 2, 3});
    OV3fProperty v3f_prop(parent_prop, prefix + "_v3f");
    v3f_prop.set({1.0f, 2.0f, 3.0f});
    OV3dProperty v3d_prop(parent_prop, prefix + "_v3d");
    v3d_prop.set({1.0, 2.0, 3.0});
    
    OP2sProperty p2s_prop(parent_prop, prefix + "_p2s");
    p2s_prop.set({1, 2});
    OP2iProperty p2i_prop(parent_prop, prefix + "_p2i");
    p2i_prop.set({1, 2});
    OP2fProperty p2f_prop(parent_prop, prefix + "_p2f");
    p2f_prop.set({1.0f, 2.0f});
    OP2dProperty p2d_prop(parent_prop, prefix + "_p2d");
    p2d_prop.set({1.0, 2.0});

    OP3sProperty p3s_prop(parent_prop, prefix + "_p3s");
    p3s_prop.set({1, 2, 3});
    OP3iProperty p3i_prop(parent_prop, prefix + "_p3i");
    p3i_prop.set({1, 2, 3});
    OP3fProperty p3f_prop(parent_prop, prefix + "_p3f");
    p3f_prop.set({1.0f, 2.0f, 3.0f});
    OP3dProperty p3d_prop(parent_prop, prefix + "_p3d");
    p3d_prop.set({1.0, 2.0, 3.0});

    OBox2sProperty box2s_prop(parent_prop, prefix + "_box2s");
    box2s_prop.set({{-1,-1}, {1,1}});
    OBox2iProperty box2i_prop(parent_prop, prefix + "_box2i");
    box2i_prop.set({{-1,-1}, {1, 1}});
    OBox2fProperty box2f_prop(parent_prop, prefix + "_box2f");
    box2f_prop.set({{-1.0f, -1.0f}, {1.0f, 1.0f}});
    OBox2dProperty box2d_prop(parent_prop, prefix + "_box2d");
    box2d_prop.set({{-1.0, -1.0}, {1.0, 1.0}});

    OBox3sProperty box3s_prop(parent_prop, prefix + "_box3s");
    box3s_prop.set({{-1, -1, -1}, {1, 1, 1}});
    OBox3iProperty box3i_prop(parent_prop, prefix + "_box3i");
    box3i_prop.set({{-1, -1, -1}, {1, 1, 1}});
    OBox3fProperty box3f_prop(parent_prop, prefix + "_box3f");
    box3f_prop.set({{-1.0f, -1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}});
    OBox3dProperty box3d_prop(parent_prop, prefix + "_box3d");
    box3d_prop.set({{-1.0, -1.0, -1.0}, {1.0, 1.0, 1.0}});
    
    Alembic::Abc::M33f identity33f;
    identity33f.makeIdentity();
    OM33fProperty m33f_prop(parent_prop, prefix + "_m33f");
    m33f_prop.set(identity33f);
    Alembic::Abc::M33d identity33d;
    identity33d.makeIdentity();
    OM33dProperty m33d_prop(parent_prop, prefix + "_m33d");
    m33d_prop.set(identity33d);
    Alembic::Abc::M44f identity44f;
    identity44f.makeIdentity();
    OM44fProperty m44f_prop(parent_prop, prefix + "_m44f");
    m44f_prop.set(identity44f);
    Alembic::Abc::M44d identity44d;
    identity44d.makeIdentity();
    OM44dProperty m44d_prop(parent_prop, prefix + "_m44d");
    m44d_prop.set(identity44d);
    
    OQuatfProperty quatf_prop(parent_prop, prefix + "_quatf");
    quatf_prop.set({1.0f, 2.0f, 3.0f, 4.0f});
    OQuatdProperty quatd_prop(parent_prop, prefix + "_quatd");
    quatd_prop.set({1.0, 2.0, 3.0, 4.0});
    
    OC3hProperty c3h_prop(parent_prop, prefix + "_c3h");
    c3h_prop.set({1.0, 2.0, 3.0});
    OC3fProperty c3f_prop(parent_prop, prefix + "_c3f");
    c3f_prop.set({1.0f, 2.0f, 3.0f});
    OC3cProperty c3c_prop(parent_prop, prefix + "_c3c");
    c3c_prop.set({1, 2, 3});
    
    OC4hProperty c4h_prop(parent_prop, prefix + "_c4h");
    c4h_prop.set({1.0, 2.0, 3.0, 4.0});
    OC4fProperty c4f_prop(parent_prop, prefix + "_c4f");
    c4f_prop.set({1.0f, 2.0f, 3.0f, 4.0f});
    OC4cProperty c4c_prop(parent_prop, prefix + "_c4c");
    c4c_prop.set({1, 2, 3, 4});
    
    ON2fProperty n2f_prop(parent_prop, prefix + "_n2f");
    n2f_prop.set({1.0f, 2.0f});
    ON2dProperty n2d_prop(parent_prop, prefix + "_n2d");
    n2d_prop.set({1.0, 2.0});
    
    ON3fProperty n3f_prop(parent_prop, prefix + "_n3f");
    n3f_prop.set({1.0f, 2.0f, 3.0f});
    ON3dProperty n3d_prop(parent_prop, prefix + "_n3d");
    n3d_prop.set({1.0, 2.0, 3.0});

    return;
}

void add_array_props(OCompoundProperty &parent_prop,
                     const std::string prefix,
                     const size_t size,
                     const MetaData &metadata) {
    
    OBoolArrayProperty bool_prop(parent_prop, prefix + "_bool", metadata);
    std::vector<bool_t> bool_vals = BOOLS_24;
    bool_vals.resize(size);
    bool_prop.set( BoolArraySample( bool_vals ) );

    OUcharArrayProperty uchar_prop(parent_prop, prefix + "_uchar", metadata);
    std::vector<uint8_t> uchar_vals = NUMERICS_24;
    uchar_vals.resize(size);
    uchar_prop.set( UcharArraySample( uchar_vals ) );

    OCharArrayProperty char_prop(parent_prop, prefix + "_char", metadata);
    std::vector<int8_t> char_vals = NUMERICS_24;
    char_vals.resize(size);
    char_prop.set( CharArraySample( char_vals ) );

    OUInt16ArrayProperty uint16_prop(parent_prop, prefix + "_uint16", metadata);
    std::vector<uint16_t> uint16_vals = NUMERICS_24;
    uint16_vals.resize(size);
    uint16_prop.set( UInt16ArraySample( uint16_vals ) );

    OInt16ArrayProperty int16_prop(parent_prop, prefix + "_int16", metadata);
    std::vector<int16_t> int16_vals = NUMERICS_24;
    int16_vals.resize(size);
    int16_prop.set( Int16ArraySample( int16_vals ) );

    OUInt32ArrayProperty uint32_prop(parent_prop, prefix + "_uint32", metadata);
    std::vector<uint32_t> uint32_vals = NUMERICS_24;
    uint32_vals.resize(size);
    uint32_prop.set( UInt32ArraySample( uint32_vals ) );

    OInt32ArrayProperty int32_prop(parent_prop, prefix + "_int32", metadata);
    std::vector<int32_t> int32_vals = NUMERICS_24;
    int32_vals.resize(size);
    int32_prop.set( Int32ArraySample( int32_vals ) );

    OUInt64ArrayProperty uint64_prop(parent_prop, prefix + "_uint64", metadata);
    std::vector<uint64_t> uint64_vals = NUMERICS_24;
    uint64_vals.resize(size);
    uint64_prop.set( UInt64ArraySample( uint64_vals ) );

    OInt64ArrayProperty int64_prop(parent_prop, prefix + "_int64", metadata);
    std::vector<int64_t> int64_vals = NUMERICS_24;
    int64_vals.resize(size);
    int64_prop.set( Int64ArraySample( int64_vals ) );

    OHalfArrayProperty float16_prop(parent_prop, prefix + "_float16", metadata);
    std::vector<float16_t> float16_vals = NUMERICS_24;
    float16_vals.resize(size);
    float16_prop.set( HalfArraySample( float16_vals ) );

    OFloatArrayProperty float32_prop(parent_prop, prefix + "_float32", metadata);
    std::vector<float32_t> float32_vals = NUMERICS_24;
    float32_vals.resize(size);
    float32_prop.set( FloatArraySample( float32_vals ) );

    ODoubleArrayProperty float64_prop(parent_prop, prefix + "_float64", metadata);
    std::vector<float64_t> float64_vals = NUMERICS_24;
    float64_vals.resize(size);
    float64_prop.set( DoubleArraySample( float64_vals ) );


    OStringArrayProperty string_prop(parent_prop, prefix + "_string", metadata);
    std::vector<string> string_vals = STRING_24;
    string_vals.resize(size);
    string_prop.set( StringArraySample( string_vals ) );

    OWstringArrayProperty wstring_prop(parent_prop, prefix + "_wstring", metadata);
    std::vector<Alembic::Util::wstring> wstring_vals;
    wstring_vals.assign(size, L"wut");
    wstring_prop.set( WstringArraySample( wstring_vals ) );

    OV2sArrayProperty v2s_prop(parent_prop, prefix + "_v2s", metadata);
    std::vector<V2s> v2s_vals = NUMERICS2_24;
    v2s_vals.resize(size);
    v2s_prop.set( V2sArraySample( v2s_vals ) );

    OV2iArrayProperty v2i_prop(parent_prop, prefix + "_v2i", metadata);
    std::vector<V2i> v2i_vals = NUMERICS2_24;
    v2i_vals.resize(size);
    v2i_prop.set( V2iArraySample( v2i_vals ) );

    OV2fArrayProperty v2f_prop(parent_prop, prefix + "_v2f", metadata);
    std::vector<V2f> v2f_vals = NUMERICS2_24;
    v2f_vals.resize(size);
    v2f_prop.set( V2fArraySample( v2f_vals ) );

    OV2dArrayProperty v2d_prop(parent_prop, prefix + "_v2d", metadata);
    std::vector<V2d> v2d_vals = NUMERICS2_24;
    v2d_vals.resize(size);
    v2d_prop.set( V2dArraySample( v2d_vals ) );
    
    OV3sArrayProperty v3s_prop(parent_prop, prefix + "_v3s", metadata);
    std::vector<V3s> v3s_vals = NUMERICS3_24;
    v3s_vals.resize(size);
    v3s_prop.set( V3sArraySample( v3s_vals ) );

    OV3iArrayProperty v3i_prop(parent_prop, prefix + "_v3i", metadata);
    std::vector<V3i> v3i_vals = NUMERICS3_24;
    v3i_vals.resize(size);
    v3i_prop.set( V3iArraySample( v3i_vals ) );

    OV3fArrayProperty v3f_prop(parent_prop, prefix + "_v3f", metadata);
    std::vector<V3f> v3f_vals = NUMERICS3_24;
    v3f_vals.resize(size);
    v3f_prop.set( V3fArraySample( v3f_vals ) );

    OV3dArrayProperty v3d_prop(parent_prop, prefix + "_v3d", metadata);
    std::vector<V3d> v3d_vals = NUMERICS3_24;
    v3d_vals.resize(size);
    v3d_prop.set( V3dArraySample( v3d_vals ) );
    
    OP2sArrayProperty p2s_prop(parent_prop, prefix + "_p2s", metadata);
    std::vector<V2s> p2s_vals = NUMERICS2_24;
    p2s_vals.resize(size);
    p2s_prop.set( P2sArraySample( p2s_vals ) );

    OP2iArrayProperty p2i_prop(parent_prop, prefix + "_p2i", metadata);
    std::vector<V2i> p2i_vals = NUMERICS2_24;
    p2i_vals.resize(size);
    p2i_prop.set( P2iArraySample( p2i_vals ) );

    OP2fArrayProperty p2f_prop(parent_prop, prefix + "_p2f", metadata);
    std::vector<V2f> p2f_vals = NUMERICS2_24;
    p2f_vals.resize(size);
    p2f_prop.set( P2fArraySample( p2f_vals ) );

    OP2dArrayProperty p2d_prop(parent_prop, prefix + "_p2d", metadata);
    std::vector<V2d> p2d_vals = NUMERICS2_24;
    p2d_vals.resize(size);
    p2d_prop.set( P2dArraySample( p2d_vals ) );
    
    OP3sArrayProperty p3s_prop(parent_prop, prefix + "_p3s", metadata);
    std::vector<V3s> p3s_vals = NUMERICS3_24;
    p3s_vals.resize(size);
    p3s_prop.set( P3sArraySample( p3s_vals ) );

    OP3iArrayProperty p3i_prop(parent_prop, prefix + "_p3i", metadata);
    std::vector<V3i> p3i_vals = NUMERICS3_24;
    p3i_vals.resize(size);
    p3i_prop.set( P3iArraySample( p3i_vals ) );

    OP3fArrayProperty p3f_prop(parent_prop, prefix + "_p3f", metadata);
    std::vector<V3f> p3f_vals = NUMERICS3_24;
    p3f_vals.resize(size);
    p3f_prop.set( P3fArraySample( p3f_vals ) );

    OP3dArrayProperty p3d_prop(parent_prop, prefix + "_p3d", metadata);
    std::vector<V3d> p3d_vals = NUMERICS3_24;
    p3d_vals.resize(size);
    p3d_prop.set( P3dArraySample( p3d_vals ) );
    
    OBox2sArrayProperty box2s_prop(parent_prop, prefix + "_box2s", metadata);
    std::vector<Box2s> box2s_vals = BOX2_24;
    box2s_vals.resize(size);
    box2s_prop.set( Box2sArraySample( box2s_vals ) );

    OBox2iArrayProperty box2i_prop(parent_prop, prefix + "_box2i", metadata);
    std::vector<Box2i> box2i_vals = BOX2_24;
    box2i_vals.resize(size);
    box2i_prop.set( Box2iArraySample( box2i_vals ) );

    OBox2fArrayProperty box2f_prop(parent_prop, prefix + "_box2f", metadata);
    std::vector<Box2f> box2f_vals = BOX2_24;
    box2f_vals.resize(size);
    box2f_prop.set( Box2fArraySample( box2f_vals ) );

    OBox2dArrayProperty box2d_prop(parent_prop, prefix + "_box2d", metadata);
    std::vector<Box2d> box2d_vals = BOX2_24;
    box2d_vals.resize(size);
    box2d_prop.set( Box2dArraySample( box2d_vals ) );
    
    OBox3sArrayProperty box3s_prop(parent_prop, prefix + "_box3s", metadata);
    std::vector<Box3s> box3s_vals = BOX3_24;
    box3s_vals.resize(size);
    box3s_prop.set( Box3sArraySample( box3s_vals ) );

    OBox3iArrayProperty box3i_prop(parent_prop, prefix + "_box3i", metadata);
    std::vector<Box3i> box3i_vals = BOX3_24;
    box3i_vals.resize(size);
    box3i_prop.set( Box3iArraySample( box3i_vals ) );

    OBox3fArrayProperty box3f_prop(parent_prop, prefix + "_box3f", metadata);
    std::vector<Box3f> box3f_vals = BOX3_24;
    box3f_vals.resize(size);
    box3f_prop.set( Box3fArraySample( box3f_vals ) );

    OBox3dArrayProperty box3d_prop(parent_prop, prefix + "_box3d", metadata);
    std::vector<Box3d> box3d_vals = BOX3_24;
    box3d_vals.resize(size);
    box3d_prop.set( Box3dArraySample( box3d_vals ) );
    
    OM33fArrayProperty m33f_prop(parent_prop, prefix + "_m33f", metadata);
    std::vector<M33f> m33f_vals;
    for (size_t i=0; i<size; ++i) {
        m33f_vals.push_back(Alembic::Abc::M33f(i));
    }
    m33f_prop.set( M33fArraySample( m33f_vals ) );

    OM33dArrayProperty m33d_prop(parent_prop, prefix + "_m33d", metadata);
    std::vector<M33d> m33d_vals;
    for (size_t i=0; i<size; ++i) {
        m33d_vals.push_back(Alembic::Abc::M33d(i));
    }
    m33d_prop.set( M33dArraySample( m33d_vals ) );
    
    OM44fArrayProperty m44f_prop(parent_prop, prefix + "_m44f", metadata);
    std::vector<M44f> m44f_vals;
    for (size_t i=0; i<size; ++i) {
        m44f_vals.push_back(Alembic::Abc::M44f(i));
    }
    m44f_prop.set( M44fArraySample( m44f_vals ) );

    OM44dArrayProperty m44d_prop(parent_prop, prefix + "_m44d", metadata);
    std::vector<M44d> m44d_vals;
    for (size_t i=0; i<size; ++i) {
        m44d_vals.push_back(Alembic::Abc::M44d(i));
    }
    m44d_prop.set( M44dArraySample( m44d_vals ) );
    
    OC3hArrayProperty c3h_prop(parent_prop, prefix + "_c3h", metadata);
    std::vector<C3h> c3h_vals = NUMERICS3_24;
    c3h_vals.resize(size);
    c3h_prop.set( C3hArraySample( c3h_vals ) );
    
    OC3fArrayProperty c3f_prop(parent_prop, prefix + "_c3f", metadata);
    std::vector<C3f> c3f_vals = NUMERICS3_24;
    c3f_vals.resize(size);
    c3f_prop.set( C3fArraySample( c3f_vals ) );

    OC3cArrayProperty c3c_prop(parent_prop, prefix + "_c3c", metadata);
    std::vector<C3c> c3c_vals = NUMERICS3_24;
    c3c_vals.resize(size);
    c3c_prop.set( C3cArraySample( c3c_vals ) );
    
    OC4hArrayProperty c4h_prop(parent_prop, prefix + "_c4h", metadata);
    std::vector<C4h> c4h_vals = NUMERICS4_24;
    c4h_vals.resize(size);
    c4h_prop.set( C4hArraySample( c4h_vals ) );
    
    OC4fArrayProperty c4f_prop(parent_prop, prefix + "_c4f", metadata);
    std::vector<C4f> c4f_vals = NUMERICS4_24;
    c4f_vals.resize(size);
    c4f_prop.set( C4fArraySample( c4f_vals ) );

    OC4cArrayProperty c4c_prop(parent_prop, prefix + "_c4c", metadata);
    std::vector<C4c> c4c_vals = NUMERICS4_24;
    c4c_vals.resize(size);
    c4c_prop.set( C4cArraySample( c4c_vals ) );
    
    OQuatfArrayProperty quatf_prop(parent_prop, prefix + "_quatf", metadata);
    std::vector<Quatf> quatf_vals = NUMERICS4_24;
    quatf_vals.resize(size);
    quatf_prop.set( QuatfArraySample( quatf_vals ) );

    OQuatdArrayProperty quatd_prop(parent_prop, prefix + "_quatd", metadata);
    std::vector<Quatd> quatd_vals = NUMERICS4_24;
    quatd_vals.resize(size);
    quatd_prop.set( QuatdArraySample( quatd_vals ) );
    
    ON2fArrayProperty n2f_prop(parent_prop, prefix + "_n2f", metadata);
    std::vector<V2f> n2f_vals = NUMERICS2_24;
    n2f_vals.resize(size);
    n2f_prop.set( N2fArraySample( n2f_vals ) );

    ON2dArrayProperty n2d_prop(parent_prop, prefix + "_n2d", metadata);
    std::vector<V2d> n2d_vals = NUMERICS2_24;
    n2d_vals.resize(size);
    n2d_prop.set( N2dArraySample( n2d_vals ) );
    
    ON3fArrayProperty n3f_prop(parent_prop, prefix + "_n3f", metadata);
    std::vector<V3f> n3f_vals = NUMERICS3_24;
    n3f_vals.resize(size);
    n3f_prop.set( N3fArraySample( n3f_vals ) );

    ON3dArrayProperty n3d_prop(parent_prop, prefix + "_n3d", metadata);
    std::vector<V3d> n3d_vals = NUMERICS3_24;
    n3d_vals.resize(size);
    n3d_prop.set( N3dArraySample( n3d_vals ) );
    
    return;
}

int main() {
    {
        Alembic::Abc::OArchive archive;
        archive = Alembic::Abc::CreateArchiveWithInfo(
            Alembic::AbcCoreOgawa::WriteArchive(), "abc_datatypes.abc",
            "abc_out", "shadeops");
        OXform test_xform(archive.getTop(), "test_obj");
        
        OXformSchema &xform = test_xform.getSchema();
        
        Alembic::Abc::M44d identity;
        identity.makeIdentity();
        Alembic::AbcGeom::XformSample samp;
        samp.addOp( XformOp( Alembic::AbcGeom::kMatrixOperation,
                             Alembic::AbcGeom::kMatrixHint),
                    identity);
    
        xform.set(samp);

        OCompoundProperty xform_arbattrs = xform.getArbGeomParams();
        add_props(xform_arbattrs, "con_arbattr");
        
        OCompoundProperty xform_userprops = xform.getUserProperties();
        add_props(xform_userprops, "user");

        OPolyMesh test_mesh(test_xform, "test_mesh");
        OPolyMeshSchema &mesh = test_mesh.getSchema();

        std::vector<V3f> box_verts(BOX_VERTS);
        std::vector<int32_t> box_indices(BOX_INDICES);
        std::vector<int32_t> box_faces(BOX_FACES);
        
        // The following will fail to compile if all 3 args are "temporaries"
        Int32ArraySample faces(box_faces);
        OPolyMeshSchema::Sample mesh_samp(
            P3fArraySample( box_verts ),
            Int32ArraySample( box_indices ),
//          Int32ArraySample( box_faces )
            faces
        );
        
        mesh.set(mesh_samp);

        Box3d bbox;
        bbox.extendBy( V3d( -1.0, -1.0, -1.0 ) );
        bbox.extendBy( V3d( 1.0, 1.0, 1.0 ) );

        mesh.getChildBoundsProperty().set(bbox);

        OCompoundProperty arbattrs = mesh.getArbGeomParams();
        add_props(arbattrs, "con_arbattr");
    
        OCompoundProperty userprops = mesh.getUserProperties();
        add_props(userprops, "user");
        
        MetaData metadata;
        add_array_props(userprops, "array_user", 2, metadata);

        MetaData pt_metadata;
        SetGeometryScope(pt_metadata, kVaryingScope);
        add_array_props(arbattrs, "var_arbgeom", NUM_VERTS, pt_metadata);
        
        MetaData prim_metadata;
        SetGeometryScope(prim_metadata, kUniformScope);
        add_array_props(arbattrs, "uni_arbgeom", NUM_FACES, prim_metadata);
        
        MetaData vertex_metadata;
        SetGeometryScope(vertex_metadata, kVertexScope);
        add_array_props(arbattrs, "vtx_arbgeom", NUM_VERTS, vertex_metadata);
        
        MetaData facevarying_metadata;
        SetGeometryScope(facevarying_metadata, kFacevaryingScope);
        add_array_props(arbattrs, "fvr_arbgeom", NUM_INDICES, facevarying_metadata);

        // Alternative way....
        // Alembic::AbcCoreAbstract::MetaData metadata;
        // SetSourceName(metadata, "stuff");
        // OFloatProperty float_metadata(userprops, "float_metadata", 0, metadata);
        // float_metadata.set(42.0);
        
    }
    return 0;
}
