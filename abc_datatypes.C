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
    std::vector<bool_t> bool_vals(BOOLS_24);
    bool_vals.resize(size);
    bool_prop.set( BoolArraySample( bool_vals ) );

    OUcharArrayProperty uchar_prop(parent_prop, prefix + "_uchar", metadata);
    std::vector<uint8_t> uchar_vals(NUMERICS_24);
    uchar_vals.resize(size);
    uchar_prop.set( UcharArraySample( uchar_vals ) );

    OCharArrayProperty char_prop(parent_prop, prefix + "_char", metadata);
    std::vector<int8_t> char_vals(NUMERICS_24);
    char_vals.resize(size);
    char_prop.set( CharArraySample( char_vals ) );

    OUInt16ArrayProperty uint16_prop(parent_prop, prefix + "_uint16", metadata);
    std::vector<uint16_t> uint16_vals(NUMERICS_24);
    uint16_vals.resize(size);
    uint16_prop.set( UInt16ArraySample( uint16_vals ) );

    OInt16ArrayProperty int16_prop(parent_prop, prefix + "_int16", metadata);
    std::vector<int16_t> int16_vals(NUMERICS_24);
    int16_vals.resize(size);
    int16_prop.set( Int16ArraySample( int16_vals ) );

    OUInt32ArrayProperty uint32_prop(parent_prop, prefix + "_uint32", metadata);
    std::vector<uint32_t> uint32_vals(NUMERICS_24);
    uint32_vals.resize(size);
    uint32_prop.set( UInt32ArraySample( uint32_vals ) );

    OInt32ArrayProperty int32_prop(parent_prop, prefix + "_int32", metadata);
    std::vector<int32_t> int32_vals(NUMERICS_24);
    int32_vals.resize(size);
    int32_prop.set( Int32ArraySample( int32_vals ) );

    OUInt64ArrayProperty uint64_prop(parent_prop, prefix + "_uint64", metadata);
    std::vector<uint64_t> uint64_vals(NUMERICS_24);
    uint64_vals.resize(size);
    uint64_prop.set( UInt64ArraySample( uint64_vals ) );

    OInt64ArrayProperty int64_prop(parent_prop, prefix + "_int64", metadata);
    std::vector<int64_t> int64_vals(NUMERICS_24);
    int64_vals.resize(size);
    int64_prop.set( Int64ArraySample( int64_vals ) );

    OHalfArrayProperty float16_prop(parent_prop, prefix + "_float16", metadata);
    std::vector<float16_t> float16_vals(NUMERICS_24);
    float16_vals.resize(size);
    float16_prop.set( HalfArraySample( float16_vals ) );

    OFloatArrayProperty float32_prop(parent_prop, prefix + "_float32", metadata);
    std::vector<float32_t> float32_vals(NUMERICS_24);
    float32_vals.resize(size);
    float32_prop.set( FloatArraySample( float32_vals ) );

    ODoubleArrayProperty float64_prop(parent_prop, prefix + "_float64", metadata);
    std::vector<float64_t> float64_vals(NUMERICS_24);
    float64_vals.resize(size);
    float64_prop.set( DoubleArraySample( float64_vals ) );

    OStringArrayProperty string_prop(parent_prop, prefix + "_string", metadata);
    std::vector<string> string_vals(STRING_24);
    string_vals.resize(size);
    string_prop.set( StringArraySample( string_vals ) );

    OWstringArrayProperty wstring_prop(parent_prop, prefix + "_wstring", metadata);
    std::vector<Alembic::Util::wstring> wstring_vals;
    wstring_vals.assign(size, L"wut");
    wstring_prop.set( WstringArraySample( wstring_vals ) );

    OV2sArrayProperty v2s_prop(parent_prop, prefix + "_v2s", metadata);
    std::vector<V2s> v2s_vals(NUMERICS2_24);
    v2s_vals.resize(size);
    v2s_prop.set( V2sArraySample( v2s_vals ) );

    OV2iArrayProperty v2i_prop(parent_prop, prefix + "_v2i", metadata);
    std::vector<V2i> v2i_vals(NUMERICS2_24);
    v2i_vals.resize(size);
    v2i_prop.set( V2iArraySample( v2i_vals ) );

    OV2fArrayProperty v2f_prop(parent_prop, prefix + "_v2f", metadata);
    std::vector<V2f> v2f_vals(NUMERICS2_24);
    v2f_vals.resize(size);
    v2f_prop.set( V2fArraySample( v2f_vals ) );

    OV2dArrayProperty v2d_prop(parent_prop, prefix + "_v2d", metadata);
    std::vector<V2d> v2d_vals(NUMERICS2_24);
    v2d_vals.resize(size);
    v2d_prop.set( V2dArraySample( v2d_vals ) );
    
    OV3sArrayProperty v3s_prop(parent_prop, prefix + "_v3s", metadata);
    std::vector<V3s> v3s_vals(NUMERICS3_24);
    v3s_vals.resize(size);
    v3s_prop.set( V3sArraySample( v3s_vals ) );

    OV3iArrayProperty v3i_prop(parent_prop, prefix + "_v3i", metadata);
    std::vector<V3i> v3i_vals(NUMERICS3_24);
    v3i_vals.resize(size);
    v3i_prop.set( V3iArraySample( v3i_vals ) );

    OV3fArrayProperty v3f_prop(parent_prop, prefix + "_v3f", metadata);
    std::vector<V3f> v3f_vals(NUMERICS3_24);
    v3f_vals.resize(size);
    v3f_prop.set( V3fArraySample( v3f_vals ) );

    OV3dArrayProperty v3d_prop(parent_prop, prefix + "_v3d", metadata);
    std::vector<V3d> v3d_vals(NUMERICS3_24);
    v3d_vals.resize(size);
    v3d_prop.set( V3dArraySample( v3d_vals ) );
    
    OP2sArrayProperty p2s_prop(parent_prop, prefix + "_p2s", metadata);
    std::vector<V2s> p2s_vals(NUMERICS2_24);
    p2s_vals.resize(size);
    p2s_prop.set( P2sArraySample( p2s_vals ) );

    OP2iArrayProperty p2i_prop(parent_prop, prefix + "_p2i", metadata);
    std::vector<V2i> p2i_vals(NUMERICS2_24);
    p2i_vals.resize(size);
    p2i_prop.set( P2iArraySample( p2i_vals ) );

    OP2fArrayProperty p2f_prop(parent_prop, prefix + "_p2f", metadata);
    std::vector<V2f> p2f_vals(NUMERICS2_24);
    p2f_vals.resize(size);
    p2f_prop.set( P2fArraySample( p2f_vals ) );

    OP2dArrayProperty p2d_prop(parent_prop, prefix + "_p2d", metadata);
    std::vector<V2d> p2d_vals(NUMERICS2_24);
    p2d_vals.resize(size);
    p2d_prop.set( P2dArraySample( p2d_vals ) );
    
    OP3sArrayProperty p3s_prop(parent_prop, prefix + "_p3s", metadata);
    std::vector<V3s> p3s_vals(NUMERICS3_24);
    p3s_vals.resize(size);
    p3s_prop.set( P3sArraySample( p3s_vals ) );

    OP3iArrayProperty p3i_prop(parent_prop, prefix + "_p3i", metadata);
    std::vector<V3i> p3i_vals(NUMERICS3_24);
    p3i_vals.resize(size);
    p3i_prop.set( P3iArraySample( p3i_vals ) );

    OP3fArrayProperty p3f_prop(parent_prop, prefix + "_p3f", metadata);
    std::vector<V3f> p3f_vals(NUMERICS3_24);
    p3f_vals.resize(size);
    p3f_prop.set( P3fArraySample( p3f_vals ) );

    OP3dArrayProperty p3d_prop(parent_prop, prefix + "_p3d", metadata);
    std::vector<V3d> p3d_vals(NUMERICS3_24);
    p3d_vals.resize(size);
    p3d_prop.set( P3dArraySample( p3d_vals ) );
    
    OBox2sArrayProperty box2s_prop(parent_prop, prefix + "_box2s", metadata);
    std::vector<Box2s> box2s_vals(BOX2_24);
    box2s_vals.resize(size);
    box2s_prop.set( Box2sArraySample( box2s_vals ) );

    OBox2iArrayProperty box2i_prop(parent_prop, prefix + "_box2i", metadata);
    std::vector<Box2i> box2i_vals(BOX2_24);
    box2i_vals.resize(size);
    box2i_prop.set( Box2iArraySample( box2i_vals ) );

    OBox2fArrayProperty box2f_prop(parent_prop, prefix + "_box2f", metadata);
    std::vector<Box2f> box2f_vals(BOX2_24);
    box2f_vals.resize(size);
    box2f_prop.set( Box2fArraySample( box2f_vals ) );

    OBox2dArrayProperty box2d_prop(parent_prop, prefix + "_box2d", metadata);
    std::vector<Box2d> box2d_vals(BOX2_24);
    box2d_vals.resize(size);
    box2d_prop.set( Box2dArraySample( box2d_vals ) );
    
    OBox3sArrayProperty box3s_prop(parent_prop, prefix + "_box3s", metadata);
    std::vector<Box3s> box3s_vals(BOX3_24);
    box3s_vals.resize(size);
    box3s_prop.set( Box3sArraySample( box3s_vals ) );

    OBox3iArrayProperty box3i_prop(parent_prop, prefix + "_box3i", metadata);
    std::vector<Box3i> box3i_vals(BOX3_24);
    box3i_vals.resize(size);
    box3i_prop.set( Box3iArraySample( box3i_vals ) );

    OBox3fArrayProperty box3f_prop(parent_prop, prefix + "_box3f", metadata);
    std::vector<Box3f> box3f_vals(BOX3_24);
    box3f_vals.resize(size);
    box3f_prop.set( Box3fArraySample( box3f_vals ) );

    OBox3dArrayProperty box3d_prop(parent_prop, prefix + "_box3d", metadata);
    std::vector<Box3d> box3d_vals(BOX3_24);
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
    std::vector<C3h> c3h_vals(NUMERICS3_24);
    c3h_vals.resize(size);
    c3h_prop.set( C3hArraySample( c3h_vals ) );
    
    OC3fArrayProperty c3f_prop(parent_prop, prefix + "_c3f", metadata);
    std::vector<C3f> c3f_vals(NUMERICS3_24);
    c3f_vals.resize(size);
    c3f_prop.set( C3fArraySample( c3f_vals ) );

    OC3cArrayProperty c3c_prop(parent_prop, prefix + "_c3c", metadata);
    std::vector<C3c> c3c_vals(NUMERICS3_24);
    c3c_vals.resize(size);
    c3c_prop.set( C3cArraySample( c3c_vals ) );
    
    OC4hArrayProperty c4h_prop(parent_prop, prefix + "_c4h", metadata);
    std::vector<C4h> c4h_vals(NUMERICS4_24);
    c4h_vals.resize(size);
    c4h_prop.set( C4hArraySample( c4h_vals ) );
    
    OC4fArrayProperty c4f_prop(parent_prop, prefix + "_c4f", metadata);
    std::vector<C4f> c4f_vals(NUMERICS4_24);
    c4f_vals.resize(size);
    c4f_prop.set( C4fArraySample( c4f_vals ) );

    OC4cArrayProperty c4c_prop(parent_prop, prefix + "_c4c", metadata);
    std::vector<C4c> c4c_vals(NUMERICS4_24);
    c4c_vals.resize(size);
    c4c_prop.set( C4cArraySample( c4c_vals ) );
    
    OQuatfArrayProperty quatf_prop(parent_prop, prefix + "_quatf", metadata);
    std::vector<Quatf> quatf_vals(NUMERICS4_24);
    quatf_vals.resize(size);
    quatf_prop.set( QuatfArraySample( quatf_vals ) );

    OQuatdArrayProperty quatd_prop(parent_prop, prefix + "_quatd", metadata);
    std::vector<Quatd> quatd_vals(NUMERICS4_24);
    quatd_vals.resize(size);
    quatd_prop.set( QuatdArraySample( quatd_vals ) );
    
    ON2fArrayProperty n2f_prop(parent_prop, prefix + "_n2f", metadata);
    std::vector<V2f> n2f_vals(NUMERICS2_24);
    n2f_vals.resize(size);
    n2f_prop.set( N2fArraySample( n2f_vals ) );

    ON2dArrayProperty n2d_prop(parent_prop, prefix + "_n2d", metadata);
    std::vector<V2d> n2d_vals(NUMERICS2_24);
    n2d_vals.resize(size);
    n2d_prop.set( N2dArraySample( n2d_vals ) );
    
    ON3fArrayProperty n3f_prop(parent_prop, prefix + "_n3f", metadata);
    std::vector<V3f> n3f_vals(NUMERICS3_24);
    n3f_vals.resize(size);
    n3f_prop.set( N3fArraySample( n3f_vals ) );

    ON3dArrayProperty n3d_prop(parent_prop, prefix + "_n3d", metadata);
    std::vector<V3d> n3d_vals(NUMERICS3_24);
    n3d_vals.resize(size);
    n3d_prop.set( N3dArraySample( n3d_vals ) );
    
    return;
}

void add_array_arbgeom(OCompoundProperty &parent_prop,
                       const std::string prefix,
                       const bool indexed,
                       const GeometryScope scope,
                       const size_t array_size) {
   
    size_t data_size = 0;
    switch (scope) {
        case kConstantScope: data_size = 1; break;
        case kUniformScope: data_size = NUM_FACES; break;
        case kVaryingScope: data_size = NUM_VERTS; break;
        case kVertexScope: data_size = NUM_VERTS; break;
        case kFacevaryingScope: data_size = NUM_INDICES; break;
        default: data_size = 0;
    }

    std::vector<uint32_t> index_vals;
    for (int i=0; i<data_size; ++i) {
        index_vals.push_back(i % 2);
    }
    UInt32ArraySample indices(index_vals);

    size_t size = data_size * array_size;
    if (indexed) size = 2 * array_size;

    OBoolGeomParam bool_param(parent_prop, prefix + "_bool", indexed, scope, array_size);
    std::vector<bool_t> bool_vals(BOOLS_24);
    bool_vals.resize(size);
    OBoolGeomParam::Sample bool_samp(BoolArraySample( bool_vals ), scope);
    if (indexed) bool_samp.setIndices(indices);
    bool_param.set(bool_samp);

    OUcharGeomParam uchar_param(parent_prop, prefix + "_uchar", indexed, scope, array_size);
    std::vector<uint8_t> uchar_vals(NUMERICS_24);
    uchar_vals.resize(size);
    OUcharGeomParam::Sample uchar_samp(UcharArraySample( uchar_vals ), scope);
    if (indexed) uchar_samp.setIndices(indices);
    uchar_param.set(uchar_samp);

    OCharGeomParam char_param(parent_prop, prefix + "_char", indexed, scope, array_size);
    std::vector<int8_t> char_vals(NUMERICS_24);
    char_vals.resize(size);
    OCharGeomParam::Sample char_samp(CharArraySample( char_vals ), scope);
    if (indexed) char_samp.setIndices(indices);
    char_param.set(char_samp);

    OUInt16GeomParam uint16_param(parent_prop, prefix + "_uint16", indexed, scope, array_size);
    std::vector<uint16_t> uint16_vals(NUMERICS_24);
    uint16_vals.resize(size);
    OUInt16GeomParam::Sample uint16_samp(UInt16ArraySample( uint16_vals ), scope);
    if (indexed) uint16_samp.setIndices(indices);
    uint16_param.set(uint16_samp);

    OInt16GeomParam int16_param(parent_prop, prefix + "_int16", indexed, scope, array_size);
    std::vector<int16_t> int16_vals(NUMERICS_24);
    int16_vals.resize(size);
    OInt16GeomParam::Sample int16_samp(Int16ArraySample( int16_vals ), scope);
    if (indexed) int16_samp.setIndices(indices);
    int16_param.set(int16_samp);

    OUInt32GeomParam uint32_param(parent_prop, prefix + "_uint32", indexed, scope, array_size);
    std::vector<uint32_t> uint32_vals(NUMERICS_24);
    uint32_vals.resize(size);
    OUInt32GeomParam::Sample uint32_samp(UInt32ArraySample( uint32_vals ), scope);
    if (indexed) uint32_samp.setIndices(indices);
    uint32_param.set(uint32_samp);

    OInt32GeomParam int32_param(parent_prop, prefix + "_int32", indexed, scope, array_size);
    std::vector<int32_t> int32_vals(NUMERICS_24);
    int32_vals.resize(size);
    OInt32GeomParam::Sample int32_samp(Int32ArraySample( int32_vals ), scope);
    if (indexed) int32_samp.setIndices(indices);
    int32_param.set(int32_samp);

    OUInt64GeomParam uint64_param(parent_prop, prefix + "_uint64", indexed, scope, array_size);
    std::vector<uint64_t> uint64_vals(NUMERICS_24);
    uint64_vals.resize(size);
    OUInt64GeomParam::Sample uint64_samp(UInt64ArraySample( uint64_vals ), scope);
    if (indexed) uint64_samp.setIndices(indices);
    uint64_param.set(uint64_samp);

    OInt64GeomParam int64_param(parent_prop, prefix + "_int64", indexed, scope, array_size);
    std::vector<int64_t> int64_vals(NUMERICS_24);
    int64_vals.resize(size);
    OInt64GeomParam::Sample int64_samp(Int64ArraySample( int64_vals ), scope);
    if (indexed) int64_samp.setIndices(indices);
    int64_param.set(int64_samp);

    OHalfGeomParam half_param(parent_prop, prefix + "_float16", indexed, scope, array_size);
    std::vector<float16_t> half_vals(NUMERICS_24);
    half_vals.resize(size);
    OHalfGeomParam::Sample half_samp(HalfArraySample( half_vals ), scope);
    if (indexed) half_samp.setIndices(indices);
    half_param.set(half_samp);

    OFloatGeomParam float_param(parent_prop, prefix + "_float32", indexed, scope, array_size);
    std::vector<float32_t> float_vals(NUMERICS_24);
    float_vals.resize(size);
    OFloatGeomParam::Sample float_samp(FloatArraySample( float_vals ), scope);
    if (indexed) float_samp.setIndices(indices);
    float_param.set(float_samp);

    ODoubleGeomParam double_param(parent_prop, prefix + "_float64", indexed, scope, array_size);
    std::vector<float64_t> double_vals(NUMERICS_24);
    double_vals.resize(size);
    ODoubleGeomParam::Sample double_samp(DoubleArraySample( double_vals ), scope);
    if (indexed) double_samp.setIndices(indices);
    double_param.set(double_samp);

    OStringGeomParam string_param(parent_prop, prefix + "_string", indexed, scope, array_size);
    std::vector<string> string_vals(STRING_24);
    string_vals.resize(size);
    OStringGeomParam::Sample string_samp(StringArraySample( string_vals ), scope);
    if (indexed) string_samp.setIndices(indices);
    string_param.set(string_samp);

    OWstringGeomParam wstring_param(parent_prop, prefix + "_wstring", indexed, scope, array_size);
    std::vector<Alembic::Util::wstring> wstring_vals;
    wstring_vals.assign(size, L"wut");
    OWstringGeomParam::Sample wstring_samp(WstringArraySample( wstring_vals ), scope);
    if (indexed) wstring_samp.setIndices(indices);
    wstring_param.set(wstring_samp);

    OV2sGeomParam v2s_param(parent_prop, prefix + "_v2s", indexed, scope, array_size);
    std::vector<V2s> v2s_vals(NUMERICS2_24);
    v2s_vals.resize(size);
    OV2sGeomParam::Sample v2s_samp(V2sArraySample( v2s_vals ), scope);
    if (indexed) v2s_samp.setIndices(indices);
    v2s_param.set(v2s_samp);

    OV2iGeomParam v2i_param(parent_prop, prefix + "_v2i", indexed, scope, array_size);
    std::vector<V2i> v2i_vals(NUMERICS2_24);
    v2i_vals.resize(size);
    OV2iGeomParam::Sample v2i_samp(V2iArraySample( v2i_vals ), scope);
    if (indexed) v2i_samp.setIndices(indices);
    v2i_param.set(v2i_samp);

    OV2fGeomParam v2f_param(parent_prop, prefix + "_v2f", indexed, scope, array_size);
    std::vector<V2f> v2f_vals(NUMERICS2_24);
    v2f_vals.resize(size);
    OV2fGeomParam::Sample v2f_samp(V2fArraySample( v2f_vals ), scope);
    if (indexed) v2f_samp.setIndices(indices);
    v2f_param.set(v2f_samp);

    OV2dGeomParam v2d_param(parent_prop, prefix + "_v2d", indexed, scope, array_size);
    std::vector<V2d> v2d_vals(NUMERICS2_24);
    v2d_vals.resize(size);
    OV2dGeomParam::Sample v2d_samp(V2dArraySample( v2d_vals ), scope);
    if (indexed) v2d_samp.setIndices(indices);
    v2d_param.set(v2d_samp);
    
    OV3sGeomParam v3s_param(parent_prop, prefix + "_v3s", indexed, scope, array_size);
    std::vector<V3s> v3s_vals(NUMERICS3_24);
    v3s_vals.resize(size);
    OV3sGeomParam::Sample v3s_samp(V3sArraySample( v3s_vals ), scope);
    if (indexed) v3s_samp.setIndices(indices);
    v3s_param.set(v3s_samp);

    OV3iGeomParam v3i_param(parent_prop, prefix + "_v3i", indexed, scope, array_size);
    std::vector<V3i> v3i_vals(NUMERICS3_24);
    v3i_vals.resize(size);
    OV3iGeomParam::Sample v3i_samp(V3iArraySample( v3i_vals ), scope);
    if (indexed) v3i_samp.setIndices(indices);
    v3i_param.set(v3i_samp);

    OV3fGeomParam v3f_param(parent_prop, prefix + "_v3f", indexed, scope, array_size);
    std::vector<V3f> v3f_vals(NUMERICS3_24);
    v3f_vals.resize(size);
    OV3fGeomParam::Sample v3f_samp(V3fArraySample( v3f_vals ), scope);
    if (indexed) v3f_samp.setIndices(indices);
    v3f_param.set(v3f_samp);

    OV3dGeomParam v3d_param(parent_prop, prefix + "_v3d", indexed, scope, array_size);
    std::vector<V3d> v3d_vals(NUMERICS3_24);
    v3d_vals.resize(size);
    OV3dGeomParam::Sample v3d_samp(V3dArraySample( v3d_vals ), scope);
    if (indexed) v3d_samp.setIndices(indices);
    v3d_param.set(v3d_samp);
    
    OP2sGeomParam p2s_param(parent_prop, prefix + "_p2s", indexed, scope, array_size);
    std::vector<V2s> p2s_vals(NUMERICS2_24);
    p2s_vals.resize(size);
    OP2sGeomParam::Sample p2s_samp(P2sArraySample( p2s_vals ), scope);
    if (indexed) p2s_samp.setIndices(indices);
    p2s_param.set(p2s_samp);

    OP2iGeomParam p2i_param(parent_prop, prefix + "_p2i", indexed, scope, array_size);
    std::vector<V2i> p2i_vals(NUMERICS2_24);
    p2i_vals.resize(size);
    OP2iGeomParam::Sample p2i_samp(P2iArraySample( p2i_vals ), scope);
    if (indexed) p2i_samp.setIndices(indices);
    p2i_param.set(p2i_samp);

    OP2fGeomParam p2f_param(parent_prop, prefix + "_p2f", indexed, scope, array_size);
    std::vector<V2f> p2f_vals(NUMERICS2_24);
    p2f_vals.resize(size);
    OP2fGeomParam::Sample p2f_samp(P2fArraySample( p2f_vals ), scope);
    if (indexed) p2f_samp.setIndices(indices);
    p2f_param.set(p2f_samp);

    OP2dGeomParam p2d_param(parent_prop, prefix + "_p2d", indexed, scope, array_size);
    std::vector<V2d> p2d_vals(NUMERICS2_24);
    p2d_vals.resize(size);
    OP2dGeomParam::Sample p2d_samp(P2dArraySample( p2d_vals ), scope);
    if (indexed) p2d_samp.setIndices(indices);
    p2d_param.set(p2d_samp);
    
    OP3sGeomParam p3s_param(parent_prop, prefix + "_p3s", indexed, scope, array_size);
    std::vector<V3s> p3s_vals(NUMERICS3_24);
    p3s_vals.resize(size);
    OP3sGeomParam::Sample p3s_samp(P3sArraySample( p3s_vals ), scope);
    if (indexed) p3s_samp.setIndices(indices);
    p3s_param.set(p3s_samp);

    OP3iGeomParam p3i_param(parent_prop, prefix + "_p3i", indexed, scope, array_size);
    std::vector<V3i> p3i_vals(NUMERICS3_24);
    p3i_vals.resize(size);
    OP3iGeomParam::Sample p3i_samp(P3iArraySample( p3i_vals ), scope);
    if (indexed) p3i_samp.setIndices(indices);
    p3i_param.set(p3i_samp);

    OP3fGeomParam p3f_param(parent_prop, prefix + "_p3f", indexed, scope, array_size);
    std::vector<V3f> p3f_vals(NUMERICS3_24);
    p3f_vals.resize(size);
    OP3fGeomParam::Sample p3f_samp(P3fArraySample( p3f_vals ), scope);
    if (indexed) p3f_samp.setIndices(indices);
    p3f_param.set(p3f_samp);

    OP3dGeomParam p3d_param(parent_prop, prefix + "_p3d", indexed, scope, array_size);
    std::vector<V3d> p3d_vals(NUMERICS3_24);
    p3d_vals.resize(size);
    OP3dGeomParam::Sample p3d_samp(P3dArraySample( p3d_vals ), scope);
    if (indexed) p3d_samp.setIndices(indices);
    p3d_param.set(p3d_samp);
    
    OBox2sGeomParam box2s_param(parent_prop, prefix + "_box2s", indexed, scope, array_size);
    std::vector<Box2s> box2s_vals(BOX2_24);
    box2s_vals.resize(size);
    OBox2sGeomParam::Sample box2s_samp(Box2sArraySample( box2s_vals ), scope);
    if (indexed) box2s_samp.setIndices(indices);
    box2s_param.set(box2s_samp);

    OBox2iGeomParam box2i_param(parent_prop, prefix + "_box2i", indexed, scope, array_size);
    std::vector<Box2i> box2i_vals(BOX2_24);
    box2i_vals.resize(size);
    OBox2iGeomParam::Sample box2i_samp(Box2iArraySample( box2i_vals ), scope);
    if (indexed) box2i_samp.setIndices(indices);
    box2i_param.set(box2i_samp);

    OBox2fGeomParam box2f_param(parent_prop, prefix + "_box2f", indexed, scope, array_size);
    std::vector<Box2f> box2f_vals(BOX2_24);
    box2f_vals.resize(size);
    OBox2fGeomParam::Sample box2f_samp(Box2fArraySample( box2f_vals ), scope);
    if (indexed) box2f_samp.setIndices(indices);
    box2f_param.set(box2f_samp);

    OBox2dGeomParam box2d_param(parent_prop, prefix + "_box2d", indexed, scope, array_size);
    std::vector<Box2d> box2d_vals(BOX2_24);
    box2d_vals.resize(size);
    OBox2dGeomParam::Sample box2d_samp(Box2dArraySample( box2d_vals ), scope);
    if (indexed) box2d_samp.setIndices(indices);
    box2d_param.set(box2d_samp);
    
    OBox3sGeomParam box3s_param(parent_prop, prefix + "_box3s", indexed, scope, array_size);
    std::vector<Box3s> box3s_vals(BOX3_24);
    box3s_vals.resize(size);
    OBox3sGeomParam::Sample box3s_samp(Box3sArraySample( box3s_vals ), scope);
    if (indexed) box3s_samp.setIndices(indices);
    box3s_param.set(box3s_samp);

    OBox3iGeomParam box3i_param(parent_prop, prefix + "_box3i", indexed, scope, array_size);
    std::vector<Box3i> box3i_vals(BOX3_24);
    box3i_vals.resize(size);
    OBox3iGeomParam::Sample box3i_samp(Box3iArraySample( box3i_vals ), scope);
    if (indexed) box3i_samp.setIndices(indices);
    box3i_param.set(box3i_samp);

    OBox3fGeomParam box3f_param(parent_prop, prefix + "_box3f", indexed, scope, array_size);
    std::vector<Box3f> box3f_vals(BOX3_24);
    box3f_vals.resize(size);
    OBox3fGeomParam::Sample box3f_samp(Box3fArraySample( box3f_vals ), scope);
    if (indexed) box3f_samp.setIndices(indices);
    box3f_param.set(box3f_samp);

    OBox3dGeomParam box3d_param(parent_prop, prefix + "_box3d", indexed, scope, array_size);
    std::vector<Box3d> box3d_vals(BOX3_24);
    box3d_vals.resize(size);
    OBox3dGeomParam::Sample box3d_samp(Box3dArraySample( box3d_vals ), scope);
    if (indexed) box3d_samp.setIndices(indices);
    box3d_param.set(box3d_samp);
    
    OM33fGeomParam m33f_param(parent_prop, prefix + "_m33f", indexed, scope, array_size);
    std::vector<M33f> m33f_vals;
    for (size_t i=0; i<size; ++i) {
        m33f_vals.push_back(Alembic::Abc::M33f(i));
    }
    OM33fGeomParam::Sample m33f_samp(M33fArraySample( m33f_vals ), scope);
    if (indexed) m33f_samp.setIndices(indices);
    m33f_param.set(m33f_samp);

    OM33dGeomParam m33d_param(parent_prop, prefix + "_m33d", indexed, scope, array_size);
    std::vector<M33d> m33d_vals;
    for (size_t i=0; i<size; ++i) {
        m33d_vals.push_back(Alembic::Abc::M33d(i));
    }
    OM33dGeomParam::Sample m33d_samp(M33dArraySample( m33d_vals ), scope);
    if (indexed) m33d_samp.setIndices(indices);
    m33d_param.set(m33d_samp);
    
    OM44fGeomParam m44f_param(parent_prop, prefix + "_m44f", indexed, scope, array_size);
    std::vector<M44f> m44f_vals;
    for (size_t i=0; i<size; ++i) {
        m44f_vals.push_back(Alembic::Abc::M44f(i));
    }
    OM44fGeomParam::Sample m44f_samp(M44fArraySample( m44f_vals ), scope);
    if (indexed) m44f_samp.setIndices(indices);
    m44f_param.set(m44f_samp);

    OM44dGeomParam m44d_param(parent_prop, prefix + "_m44d", indexed, scope, array_size);
    std::vector<M44d> m44d_vals;
    for (size_t i=0; i<size; ++i) {
        m44d_vals.push_back(Alembic::Abc::M44d(i));
    }
    OM44dGeomParam::Sample m44d_samp(M44dArraySample( m44d_vals ), scope);
    if (indexed) m44d_samp.setIndices(indices);
    m44d_param.set(m44d_samp);
    
    OC3hGeomParam c3h_param(parent_prop, prefix + "_c3h", indexed, scope, array_size);
    std::vector<C3h> c3h_vals(NUMERICS3_24);
    c3h_vals.resize(size);
    OC3hGeomParam::Sample c3h_samp(C3hArraySample( c3h_vals ), scope);
    if (indexed) c3h_samp.setIndices(indices);
    c3h_param.set(c3h_samp);
    
    OC3fGeomParam c3f_param(parent_prop, prefix + "_c3f", indexed, scope, array_size);
    std::vector<C3f> c3f_vals(NUMERICS3_24);
    c3f_vals.resize(size);
    OC3fGeomParam::Sample c3f_samp(C3fArraySample( c3f_vals ), scope);
    if (indexed) c3f_samp.setIndices(indices);
    c3f_param.set(c3f_samp);

    OC3cGeomParam c3c_param(parent_prop, prefix + "_c3c", indexed, scope, array_size);
    std::vector<C3c> c3c_vals(NUMERICS3_24);
    c3c_vals.resize(size);
    OC3cGeomParam::Sample c3c_samp(C3cArraySample( c3c_vals ), scope);
    if (indexed) c3c_samp.setIndices(indices);
    c3c_param.set(c3c_samp);
    
    OC4hGeomParam c4h_param(parent_prop, prefix + "_c4h", indexed, scope, array_size);
    std::vector<C4h> c4h_vals(NUMERICS4_24);
    c4h_vals.resize(size);
    OC4hGeomParam::Sample c4h_samp(C4hArraySample( c4h_vals ), scope);
    if (indexed) c4h_samp.setIndices(indices);
    c4h_param.set(c4h_samp);
    
    OC4fGeomParam c4f_param(parent_prop, prefix + "_c4f", indexed, scope, array_size);
    std::vector<C4f> c4f_vals(NUMERICS4_24);
    c4f_vals.resize(size);
    OC4fGeomParam::Sample c4f_samp(C4fArraySample( c4f_vals ), scope);
    if (indexed) c4f_samp.setIndices(indices);
    c4f_param.set(c4f_samp);

    OC4cGeomParam c4c_param(parent_prop, prefix + "_c4c", indexed, scope, array_size);
    std::vector<C4c> c4c_vals(NUMERICS4_24);
    c4c_vals.resize(size);
    OC4cGeomParam::Sample c4c_samp(C4cArraySample( c4c_vals ), scope);
    if (indexed) c4c_samp.setIndices(indices);
    c4c_param.set(c4c_samp);
    
    OQuatfGeomParam quatf_param(parent_prop, prefix + "_quatf", indexed, scope, array_size);
    std::vector<Quatf> quatf_vals(NUMERICS4_24);
    quatf_vals.resize(size);
    OQuatfGeomParam::Sample quatf_samp(QuatfArraySample( quatf_vals ), scope);
    if (indexed) quatf_samp.setIndices(indices);
    quatf_param.set(quatf_samp);

    OQuatdGeomParam quatd_param(parent_prop, prefix + "_quatd", indexed, scope, array_size);
    std::vector<Quatd> quatd_vals(NUMERICS4_24);
    quatd_vals.resize(size);
    OQuatdGeomParam::Sample quatd_samp(QuatdArraySample( quatd_vals ), scope);
    if (indexed) quatd_samp.setIndices(indices);
    quatd_param.set(quatd_samp);
    
    ON2fGeomParam n2f_param(parent_prop, prefix + "_n2f", indexed, scope, array_size);
    std::vector<V2f> n2f_vals(NUMERICS2_24);
    n2f_vals.resize(size);
    ON2fGeomParam::Sample n2f_samp(N2fArraySample( n2f_vals ), scope);
    if (indexed) n2f_samp.setIndices(indices);
    n2f_param.set(n2f_samp);

    ON2dGeomParam n2d_param(parent_prop, prefix + "_n2d", indexed, scope, array_size);
    std::vector<V2d> n2d_vals(NUMERICS2_24);
    n2d_vals.resize(size);
    ON2dGeomParam::Sample n2d_samp(N2dArraySample( n2d_vals ), scope);
    if (indexed) n2d_samp.setIndices(indices);
    n2d_param.set(n2d_samp);
    
    ON3fGeomParam n3f_param(parent_prop, prefix + "_n3f", indexed, scope, array_size);
    std::vector<V3f> n3f_vals(NUMERICS3_24);
    n3f_vals.resize(size);
    ON3fGeomParam::Sample n3f_samp(N3fArraySample( n3f_vals ), scope);
    if (indexed) n3f_samp.setIndices(indices);
    n3f_param.set(n3f_samp);

    ON3dGeomParam n3d_param(parent_prop, prefix + "_n3d", indexed, scope, array_size);
    std::vector<V3d> n3d_vals(NUMERICS3_24);
    n3d_vals.resize(size);
    ON3dGeomParam::Sample n3d_samp(N3dArraySample( n3d_vals ), scope);
    if (indexed) n3d_samp.setIndices(indices);
    n3d_param.set(n3d_samp);
    
    return;
}

int main() {
    {
        Alembic::Abc::OArchive archive;
        archive = Alembic::Abc::CreateArchiveWithInfo(
            Alembic::AbcCoreOgawa::WriteArchive(), "abc_datatypes.abc",
            "abc_out", "shadeops");
        OXform test_xform(archive.getTop(), "test_obj");
        
        Box3d bbox;
        bbox.extendBy( V3d( -1.0, -1.0, -1.0 ) );
        bbox.extendBy( V3d( 1.0, 1.0, 1.0 ) );

        OXformSchema &xform = test_xform.getSchema();
        xform.getChildBoundsProperty().set(bbox);
        
        Alembic::Abc::M44d identity;
        identity.makeIdentity();
        Alembic::AbcGeom::XformSample samp;
        samp.addOp( XformOp( Alembic::AbcGeom::kMatrixOperation,
                             Alembic::AbcGeom::kMatrixHint),
                    identity);
    
        xform.set(samp);

        OCompoundProperty xform_arbgeom = xform.getArbGeomParams();
        add_props(xform_arbgeom, "arbgeom_con");
        
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

        OCompoundProperty userprops = mesh.getUserProperties();
        OCompoundProperty arbgeom = mesh.getArbGeomParams();
        add_props(userprops, "user");
        
        MetaData metadata;
        add_array_props(userprops, "user_array", 2, metadata);

        add_array_arbgeom(arbgeom, "arbgeom_array_con", false, kConstantScope, 2);
        add_array_arbgeom(arbgeom, "arbgeom_con", false, kConstantScope, 1);
        add_array_arbgeom(arbgeom, "arbgeom_uni", false, kUniformScope, 1);
        add_array_arbgeom(arbgeom, "arbgeom_indexed_uni", true, kUniformScope, 1);
        add_array_arbgeom(arbgeom, "arbgeom_indexed_array_uni", true, kUniformScope, 2);
        add_array_arbgeom(arbgeom, "arbgeom_var", false, kVaryingScope, 1);
        add_array_arbgeom(arbgeom, "arbgeom_vtx", false, kVertexScope, 1);
        add_array_arbgeom(arbgeom, "arbgeom_fvr", false, kFacevaryingScope, 1);
    }
    return 0;
}
