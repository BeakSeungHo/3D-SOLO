xof 0303txt 0032

// DirectX 9.0 file
// Creator: Ultimate Unwrap3D Pro (x64) v3.50.25
// Website: http://www.unwrap3d.com
// Time: Mon May 15 14:27:23 2017

// Start of Templates

template VertexDuplicationIndices {
 <b8d65549-d7c9-4995-89cf-53a9a8b031e3>
 DWORD nIndices;
 DWORD nOriginalVertices;
 array DWORD indices[nIndices];
}

template FVFData {
 <b6e70a0e-8ef9-4e83-94ad-ecc8b0c04897>
 DWORD dwFVF;
 DWORD nDWords;
 array DWORD data[nDWords];
}

template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template FrameTransformMatrix {
 <F6F23F41-7686-11cf-8F52-0040333594A3>
 Matrix4x4 frameMatrix;
}

template Frame {
 <3D82AB46-62DA-11cf-AB39-0020AF71E433>
 [...]
}

template FloatKeys {
 <10DD46A9-775B-11cf-8F52-0040333594A3>
 DWORD nValues;
 array FLOAT values[nValues];
}

template TimedFloatKeys {
 <F406B180-7B3B-11cf-8F52-0040333594A3>
 DWORD time;
 FloatKeys tfkeys;
}

template AnimationKey {
 <10DD46A8-775B-11cf-8F52-0040333594A3>
 DWORD keyType;
 DWORD nKeys;
 array TimedFloatKeys keys[nKeys];
}

template AnimationOptions {
 <E2BF56C0-840F-11cf-8F52-0040333594A3>
 DWORD openclosed;
 DWORD positionquality;
}

template Animation {
 <3D82AB4F-62DA-11cf-AB39-0020AF71E433>
 [...]
}

template AnimationSet {
 <3D82AB50-62DA-11cf-AB39-0020AF71E433>
 [Animation]
}

template XSkinMeshHeader {
 <3CF169CE-FF7C-44ab-93C0-F78F62D172E2>
 WORD nMaxSkinWeightsPerVertex;
 WORD nMaxSkinWeightsPerFace;
 WORD nBones;
}

template SkinWeights {
 <6F0D123B-BAD2-4167-A0D0-80224F25FABB>
 STRING transformNodeName;
 DWORD nWeights;
 array DWORD vertexIndices[nWeights];
 array FLOAT weights[nWeights];
 Matrix4x4 matrixOffset;
}

template AnimTicksPerSecond {
 <9E415A43-7BA6-4a73-8743-B73D47E88476>
 DWORD AnimTicksPerSecond;
}

AnimTicksPerSecond {
 30;
}

// Start of Frames

   Frame st_airpipe_x1 {
      FrameTransformMatrix {
       1.000000, 0.000000, -0.000000, 0.000000,
       0.000000, -0.000000, -1.000000, 0.000000,
       0.000000, 1.000000, -0.000000, 0.000000,
       0.000000, 0.000000, 0.000000, 1.000000;;
      }

   }

   Frame Body {
      FrameTransformMatrix {
       1.000000, 0.000000, 0.000000, 0.000000,
       0.000000, 1.000000, 0.000000, 0.000000,
       0.000000, 0.000000, 1.000000, 0.000000,
       0.000000, 0.000000, 0.000000, 1.000000;;
      }

      Mesh skinnedMesh {
       128;
       -42.853073; 11.999947; -4.000000;,
       -42.853073; 11.999947; -60.000000;,
       42.853073; 11.999947; -60.000000;,
       42.853073; 11.999947; -4.000000;,
       -42.853073; 99.999947; -4.000000;,
       42.853073; 99.999947; -4.000000;,
       42.853073; 99.999947; -60.000000;,
       -42.853073; 99.999947; -60.000000;,
       44.000000; 13.146873; -4.000000;,
       44.000000; 13.146870; -60.000000;,
       44.000000; 98.853027; -60.000000;,
       44.000000; 98.853027; -4.000000;,
       -44.000000; 13.146870; -60.000000;,
       -44.000000; 13.146873; -4.000000;,
       -44.000000; 98.853027; -4.000000;,
       -44.000000; 98.853027; -60.000000;,
       -42.853073; 11.999947; -4.000000;,
       -44.000000; 13.146873; -4.000000;,
       -44.000000; 13.146870; -60.000000;,
       -42.853073; 11.999947; -60.000000;,
       42.853073; 11.999947; -60.000000;,
       44.000000; 13.146870; -60.000000;,
       44.000000; 13.146873; -4.000000;,
       42.853073; 11.999947; -4.000000;,
       42.853073; 99.999947; -4.000000;,
       44.000000; 98.853027; -4.000000;,
       44.000000; 98.853027; -60.000000;,
       42.853073; 99.999947; -60.000000;,
       -42.853073; 99.999947; -60.000000;,
       -44.000000; 98.853027; -60.000000;,
       -44.000000; 98.853027; -4.000000;,
       -42.853073; 99.999947; -4.000000;,
       -48.386883; 106.129959; -58.553909;,
       48.386887; 106.129959; -58.553909;,
       48.386887; 106.129959; -64.000015;,
       -48.386883; 106.129959; -64.000015;,
       -48.386883; 106.129959; -5.446121;,
       48.386887; 106.129959; -5.446121;,
       50.129883; 104.386955; -5.446121;,
       -50.129883; 7.612938; -5.446106;,
       -50.129883; 104.386955; -5.446121;,
       48.386883; 5.869934; -5.446106;,
       50.129883; 7.612938; -5.446106;,
       -48.386883; 5.869934; -5.446106;,
       -50.129883; 7.612946; 0.000000;,
       -48.386883; 5.869949; -0.000008;,
       -50.129883; 104.386955; -0.000031;,
       48.386887; 106.129959; -0.000015;,
       -48.386883; 106.129959; -0.000015;,
       50.129883; 7.612946; 0.000000;,
       48.386883; 5.869949; -0.000008;,
       50.129883; 104.386955; -0.000031;,
       -48.386883; 106.129959; -64.000015;,
       48.386887; 106.129959; -64.000015;,
       50.129883; 104.386955; -64.000015;,
       -50.129883; 7.612938; -64.000000;,
       -50.129883; 104.386955; -64.000015;,
       48.386883; 5.869934; -64.000000;,
       50.129883; 7.612938; -64.000000;,
       -48.386883; 5.869934; -64.000000;,
       48.386887; 106.129959; -58.553909;,
       -48.386883; 106.129959; -58.553909;,
       -50.129883; 104.386955; -58.553925;,
       50.129883; 7.612946; -58.553894;,
       50.129883; 104.386955; -58.553925;,
       -48.386883; 5.869949; -58.553902;,
       -50.129883; 7.612946; -58.553894;,
       48.386883; 5.869949; -58.553902;,
       50.129883; 7.612946; -58.553894;,
       50.129883; 7.612938; -64.000000;,
       50.129883; 104.386955; -64.000015;,
       50.129883; 104.386955; -58.553925;,
       -50.129883; 104.386955; -58.553925;,
       -50.129883; 104.386955; -64.000015;,
       -50.129883; 7.612938; -64.000000;,
       -50.129883; 7.612946; -58.553894;,
       -48.386883; 5.869949; -58.553902;,
       -50.129883; 7.612946; -58.553894;,
       -50.129883; 7.612938; -64.000000;,
       -48.386883; 5.869934; -64.000000;,
       48.386883; 5.869934; -64.000000;,
       50.129883; 7.612938; -64.000000;,
       50.129883; 7.612946; -58.553894;,
       48.386883; 5.869949; -58.553902;,
       48.386887; 106.129959; -58.553909;,
       50.129883; 104.386955; -58.553925;,
       50.129883; 104.386955; -64.000015;,
       48.386887; 106.129959; -64.000015;,
       -48.386883; 106.129959; -64.000015;,
       -50.129883; 104.386955; -64.000015;,
       -50.129883; 104.386955; -58.553925;,
       -48.386883; 106.129959; -58.553909;,
       -48.386883; 5.869949; -0.000008;,
       -48.386883; 5.869934; -5.446106;,
       48.386883; 5.869934; -5.446106;,
       48.386883; 5.869949; -0.000008;,
       -48.386883; 106.129959; -0.000015;,
       48.386887; 106.129959; -0.000015;,
       48.386887; 106.129959; -5.446121;,
       -48.386883; 106.129959; -5.446121;,
       -50.129883; 7.612938; -5.446106;,
       -50.129883; 7.612946; 0.000000;,
       -50.129883; 104.386955; -0.000031;,
       -50.129883; 104.386955; -5.446121;,
       -48.386883; 5.869949; -0.000008;,
       -50.129883; 7.612946; 0.000000;,
       -50.129883; 7.612938; -5.446106;,
       -48.386883; 5.869934; -5.446106;,
       48.386883; 5.869934; -5.446106;,
       50.129883; 7.612938; -5.446106;,
       50.129883; 7.612946; 0.000000;,
       48.386883; 5.869949; -0.000008;,
       48.386887; 106.129959; -0.000015;,
       50.129883; 104.386955; -0.000031;,
       50.129883; 104.386955; -5.446121;,
       48.386887; 106.129959; -5.446121;,
       -48.386883; 106.129959; -5.446121;,
       -50.129883; 104.386955; -5.446121;,
       -50.129883; 104.386955; -0.000031;,
       -48.386883; 106.129959; -0.000015;,
       -48.386883; 5.869949; -58.553902;,
       -48.386883; 5.869934; -64.000000;,
       48.386883; 5.869934; -64.000000;,
       48.386883; 5.869949; -58.553902;,
       50.129883; 7.612946; 0.000000;,
       50.129883; 7.612938; -5.446106;,
       50.129883; 104.386955; -5.446121;,
       50.129883; 104.386955; -0.000031;;
       72;
       3;0, 1, 2;,
       3;2, 3, 0;,
       3;4, 5, 6;,
       3;6, 7, 4;,
       3;8, 9, 10;,
       3;10, 11, 8;,
       3;12, 13, 14;,
       3;14, 15, 12;,
       3;16, 17, 18;,
       3;18, 19, 16;,
       3;20, 21, 22;,
       3;22, 23, 20;,
       3;24, 25, 26;,
       3;26, 27, 24;,
       3;28, 29, 30;,
       3;30, 31, 28;,
       3;32, 33, 34;,
       3;34, 35, 32;,
       3;36, 37, 38;,
       3;39, 40, 36;,
       3;41, 39, 36;,
       3;41, 36, 38;,
       3;42, 41, 38;,
       3;41, 43, 39;,
       3;44, 45, 46;,
       3;47, 48, 46;,
       3;45, 47, 46;,
       3;45, 49, 47;,
       3;45, 50, 49;,
       3;49, 51, 47;,
       3;52, 53, 54;,
       3;55, 56, 52;,
       3;57, 55, 52;,
       3;57, 52, 54;,
       3;58, 57, 54;,
       3;57, 59, 55;,
       3;60, 61, 62;,
       3;63, 64, 60;,
       3;65, 63, 60;,
       3;65, 60, 62;,
       3;66, 65, 62;,
       3;65, 67, 63;,
       3;68, 69, 70;,
       3;70, 71, 68;,
       3;72, 73, 74;,
       3;74, 75, 72;,
       3;76, 77, 78;,
       3;78, 79, 76;,
       3;80, 81, 82;,
       3;82, 83, 80;,
       3;84, 85, 86;,
       3;86, 87, 84;,
       3;88, 89, 90;,
       3;90, 91, 88;,
       3;92, 93, 94;,
       3;94, 95, 92;,
       3;96, 97, 98;,
       3;98, 99, 96;,
       3;100, 101, 102;,
       3;102, 103, 100;,
       3;104, 105, 106;,
       3;106, 107, 104;,
       3;108, 109, 110;,
       3;110, 111, 108;,
       3;112, 113, 114;,
       3;114, 115, 112;,
       3;116, 117, 118;,
       3;118, 119, 116;,
       3;120, 121, 122;,
       3;122, 123, 120;,
       3;124, 125, 126;,
       3;126, 127, 124;;

      MeshNormals {
       128;
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; -1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -0.707106; -0.707107; 0.000000;,
       -0.707107; -0.707107; 0.000000;,
       -0.707106; -0.707107; 0.000000;,
       -0.707106; -0.707108; 0.000000;,
       0.707106; -0.707107; 0.000000;,
       0.707106; -0.707108; 0.000000;,
       0.707106; -0.707107; 0.000000;,
       0.707107; -0.707107; 0.000000;,
       0.707104; 0.707109; 0.000000;,
       0.707104; 0.707109; 0.000000;,
       0.707104; 0.707109; 0.000000;,
       0.707104; 0.707109; 0.000000;,
       -0.707104; 0.707109; 0.000000;,
       -0.707104; 0.707109; 0.000000;,
       -0.707104; 0.707109; 0.000000;,
       -0.707104; 0.707109; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; -0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; -0.000000; -1.000000;,
       0.000000; -0.000000; -1.000000;,
       0.000000; -0.000000; -1.000000;,
       0.000000; -0.000000; -1.000000;,
       0.000000; -0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000005; 0.000000; 1.000000;,
       0.000001; -0.000001; 1.000000;,
       0.000002; -0.000003; 1.000000;,
       0.000002; -0.000002; 1.000000;,
       0.000000; -0.000009; 1.000000;,
       0.000003; -0.000001; 1.000000;,
       0.000000; -0.000004; 1.000000;,
       0.000009; 0.000000; 1.000000;,
       0.000000; -0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000000; -0.000000; -1.000000;,
       0.000000; -0.000000; -1.000000;,
       0.000000; -0.000000; -1.000000;,
       0.000000; -0.000000; -1.000000;,
       0.000000; -0.000000; -1.000000;,
       0.000000; 0.000000; -1.000000;,
       0.000002; -0.000002; 1.000000;,
       0.000000; -0.000009; 1.000000;,
       0.000002; -0.000003; 1.000000;,
       0.000003; -0.000001; 1.000000;,
       0.000009; 0.000000; 1.000000;,
       0.000001; -0.000001; 1.000000;,
       0.000005; 0.000000; 1.000000;,
       0.000000; -0.000004; 1.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -0.707107; -0.707107; 0.000001;,
       -0.707106; -0.707108; 0.000001;,
       -0.707107; -0.707107; 0.000001;,
       -0.707108; -0.707106; 0.000002;,
       0.707107; -0.707107; 0.000001;,
       0.707108; -0.707106; 0.000001;,
       0.707107; -0.707107; 0.000001;,
       0.707106; -0.707108; 0.000002;,
       0.707108; 0.707105; 0.000000;,
       0.707108; 0.707105; 0.000000;,
       0.707108; 0.707105; 0.000000;,
       0.707108; 0.707105; 0.000000;,
       -0.707108; 0.707106; 0.000000;,
       -0.707108; 0.707106; 0.000000;,
       -0.707108; 0.707106; 0.000000;,
       -0.707108; 0.707106; 0.000000;,
       0.000000; -1.000000; 0.000003;,
       0.000000; -1.000000; 0.000003;,
       0.000000; -1.000000; 0.000003;,
       0.000000; -1.000000; 0.000003;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       0.000000; 1.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -1.000000; 0.000000; 0.000000;,
       -0.707107; -0.707107; 0.000001;,
       -0.707106; -0.707108; 0.000001;,
       -0.707107; -0.707107; 0.000001;,
       -0.707108; -0.707106; 0.000002;,
       0.707107; -0.707107; 0.000001;,
       0.707108; -0.707106; 0.000001;,
       0.707107; -0.707107; 0.000001;,
       0.707106; -0.707108; 0.000002;,
       0.707108; 0.707105; 0.000000;,
       0.707108; 0.707105; 0.000000;,
       0.707108; 0.707105; 0.000000;,
       0.707108; 0.707105; 0.000000;,
       -0.707108; 0.707106; 0.000000;,
       -0.707108; 0.707106; 0.000000;,
       -0.707108; 0.707106; 0.000000;,
       -0.707108; 0.707106; 0.000000;,
       0.000000; -1.000000; 0.000003;,
       0.000000; -1.000000; 0.000003;,
       0.000000; -1.000000; 0.000003;,
       0.000000; -1.000000; 0.000003;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;,
       1.000000; 0.000000; 0.000000;;
       72;
       3;0, 1, 2;,
       3;2, 3, 0;,
       3;4, 5, 6;,
       3;6, 7, 4;,
       3;8, 9, 10;,
       3;10, 11, 8;,
       3;12, 13, 14;,
       3;14, 15, 12;,
       3;16, 17, 18;,
       3;18, 19, 16;,
       3;20, 21, 22;,
       3;22, 23, 20;,
       3;24, 25, 26;,
       3;26, 27, 24;,
       3;28, 29, 30;,
       3;30, 31, 28;,
       3;32, 33, 34;,
       3;34, 35, 32;,
       3;36, 37, 38;,
       3;39, 40, 36;,
       3;41, 39, 36;,
       3;41, 36, 38;,
       3;42, 41, 38;,
       3;41, 43, 39;,
       3;44, 45, 46;,
       3;47, 48, 46;,
       3;45, 47, 46;,
       3;45, 49, 47;,
       3;45, 50, 49;,
       3;49, 51, 47;,
       3;52, 53, 54;,
       3;55, 56, 52;,
       3;57, 55, 52;,
       3;57, 52, 54;,
       3;58, 57, 54;,
       3;57, 59, 55;,
       3;60, 61, 62;,
       3;63, 64, 60;,
       3;65, 63, 60;,
       3;65, 60, 62;,
       3;66, 65, 62;,
       3;65, 67, 63;,
       3;68, 69, 70;,
       3;70, 71, 68;,
       3;72, 73, 74;,
       3;74, 75, 72;,
       3;76, 77, 78;,
       3;78, 79, 76;,
       3;80, 81, 82;,
       3;82, 83, 80;,
       3;84, 85, 86;,
       3;86, 87, 84;,
       3;88, 89, 90;,
       3;90, 91, 88;,
       3;92, 93, 94;,
       3;94, 95, 92;,
       3;96, 97, 98;,
       3;98, 99, 96;,
       3;100, 101, 102;,
       3;102, 103, 100;,
       3;104, 105, 106;,
       3;106, 107, 104;,
       3;108, 109, 110;,
       3;110, 111, 108;,
       3;112, 113, 114;,
       3;114, 115, 112;,
       3;116, 117, 118;,
       3;118, 119, 116;,
       3;120, 121, 122;,
       3;122, 123, 120;,
       3;124, 125, 126;,
       3;126, 127, 124;;
      }

      MeshTextureCoords {
       128;
       0.999512; 0.232300;,
       0.999512; 0.009773;,
       0.757324; 0.009773;,
       0.757324; 0.232300;,
       0.261230; 0.232300;,
       0.503418; 0.232300;,
       0.503418; 0.009766;,
       0.261230; 0.009773;,
       0.751465; 0.232300;,
       0.751465; 0.009766;,
       0.509277; 0.009766;,
       0.509277; 0.232300;,
       0.013435; 0.009781;,
       0.013443; 0.232300;,
       0.255615; 0.232300;,
       0.255615; 0.009773;,
       0.007801; 0.232300;,
       0.013443; 0.232300;,
       0.013435; 0.009781;,
       0.007793; 0.009781;,
       0.757324; 0.009773;,
       0.751465; 0.009766;,
       0.751465; 0.232300;,
       0.757324; 0.232300;,
       0.503418; 0.232300;,
       0.509277; 0.232300;,
       0.509277; 0.009766;,
       0.503418; 0.009766;,
       0.261230; 0.009773;,
       0.255615; 0.009773;,
       0.255615; 0.232300;,
       0.261230; 0.232300;,
       0.029419; 0.259277;,
       0.307861; 0.259277;,
       0.313965; 0.244629;,
       0.023285; 0.244629;,
       0.628906; 0.579102;,
       0.348145; 0.579102;,
       0.342041; 0.585449;,
       0.634766; 0.866211;,
       0.634766; 0.585449;,
       0.348145; 0.872070;,
       0.342041; 0.866211;,
       0.628906; 0.872070;,
       0.024963; 0.875488;,
       0.029419; 0.879883;,
       0.024963; 0.597168;,
       0.307861; 0.592773;,
       0.029419; 0.592773;,
       0.312256; 0.875488;,
       0.307861; 0.879883;,
       0.312256; 0.597168;,
       0.628906; 0.246094;,
       0.348145; 0.246094;,
       0.342041; 0.251953;,
       0.634766; 0.532715;,
       0.634766; 0.251953;,
       0.348145; 0.539063;,
       0.342041; 0.532715;,
       0.628906; 0.539063;,
       0.307861; 0.259277;,
       0.029419; 0.259277;,
       0.024963; 0.263916;,
       0.312256; 0.542480;,
       0.312256; 0.263916;,
       0.029419; 0.546875;,
       0.024963; 0.542480;,
       0.307861; 0.546875;,
       0.312256; 0.542480;,
       0.327148; 0.548340;,
       0.327148; 0.257813;,
       0.312256; 0.263916;,
       0.024963; 0.263916;,
       0.010162; 0.257813;,
       0.010162; 0.548340;,
       0.024963; 0.542480;,
       0.029419; 0.546875;,
       0.024963; 0.542480;,
       0.010162; 0.548340;,
       0.023285; 0.561523;,
       0.313965; 0.561523;,
       0.327148; 0.548340;,
       0.312256; 0.542480;,
       0.307861; 0.546875;,
       0.307861; 0.259277;,
       0.312256; 0.263916;,
       0.327148; 0.257813;,
       0.313965; 0.244629;,
       0.023285; 0.244629;,
       0.010162; 0.257813;,
       0.024963; 0.263916;,
       0.029419; 0.259277;,
       0.029419; 0.879883;,
       0.023285; 0.895020;,
       0.313965; 0.895020;,
       0.307861; 0.879883;,
       0.029419; 0.592773;,
       0.307861; 0.592773;,
       0.313965; 0.577637;,
       0.023285; 0.577637;,
       0.010162; 0.881836;,
       0.024963; 0.875488;,
       0.024963; 0.597168;,
       0.010162; 0.590820;,
       0.029419; 0.879883;,
       0.024963; 0.875488;,
       0.010162; 0.881836;,
       0.023285; 0.895020;,
       0.313965; 0.895020;,
       0.327148; 0.881836;,
       0.312256; 0.875488;,
       0.307861; 0.879883;,
       0.307861; 0.592773;,
       0.312256; 0.597168;,
       0.327148; 0.590820;,
       0.313965; 0.577637;,
       0.023285; 0.577637;,
       0.010162; 0.590820;,
       0.024963; 0.597168;,
       0.029419; 0.592773;,
       0.029419; 0.546875;,
       0.023285; 0.561523;,
       0.313965; 0.561523;,
       0.307861; 0.546875;,
       0.312256; 0.875488;,
       0.327148; 0.881836;,
       0.327148; 0.590820;,
       0.312256; 0.597168;;
      }

      MeshVertexColors {
       128;
       0; 1.000000; 1.000000; 1.000000; 1.000000;,
       1; 1.000000; 1.000000; 1.000000; 1.000000;,
       2; 1.000000; 1.000000; 1.000000; 1.000000;,
       3; 1.000000; 1.000000; 1.000000; 1.000000;,
       4; 1.000000; 1.000000; 1.000000; 1.000000;,
       5; 1.000000; 1.000000; 1.000000; 1.000000;,
       6; 1.000000; 1.000000; 1.000000; 1.000000;,
       7; 1.000000; 1.000000; 1.000000; 1.000000;,
       8; 1.000000; 1.000000; 1.000000; 1.000000;,
       9; 1.000000; 1.000000; 1.000000; 1.000000;,
       10; 1.000000; 1.000000; 1.000000; 1.000000;,
       11; 1.000000; 1.000000; 1.000000; 1.000000;,
       12; 1.000000; 1.000000; 1.000000; 1.000000;,
       13; 1.000000; 1.000000; 1.000000; 1.000000;,
       14; 1.000000; 1.000000; 1.000000; 1.000000;,
       15; 1.000000; 1.000000; 1.000000; 1.000000;,
       16; 1.000000; 1.000000; 1.000000; 1.000000;,
       17; 1.000000; 1.000000; 1.000000; 1.000000;,
       18; 1.000000; 1.000000; 1.000000; 1.000000;,
       19; 1.000000; 1.000000; 1.000000; 1.000000;,
       20; 1.000000; 1.000000; 1.000000; 1.000000;,
       21; 1.000000; 1.000000; 1.000000; 1.000000;,
       22; 1.000000; 1.000000; 1.000000; 1.000000;,
       23; 1.000000; 1.000000; 1.000000; 1.000000;,
       24; 1.000000; 1.000000; 1.000000; 1.000000;,
       25; 1.000000; 1.000000; 1.000000; 1.000000;,
       26; 1.000000; 1.000000; 1.000000; 1.000000;,
       27; 1.000000; 1.000000; 1.000000; 1.000000;,
       28; 1.000000; 1.000000; 1.000000; 1.000000;,
       29; 1.000000; 1.000000; 1.000000; 1.000000;,
       30; 1.000000; 1.000000; 1.000000; 1.000000;,
       31; 1.000000; 1.000000; 1.000000; 1.000000;,
       32; 1.000000; 1.000000; 1.000000; 1.000000;,
       33; 1.000000; 1.000000; 1.000000; 1.000000;,
       34; 1.000000; 1.000000; 1.000000; 1.000000;,
       35; 1.000000; 1.000000; 1.000000; 1.000000;,
       36; 1.000000; 1.000000; 1.000000; 1.000000;,
       37; 1.000000; 1.000000; 1.000000; 1.000000;,
       38; 1.000000; 1.000000; 1.000000; 1.000000;,
       39; 1.000000; 1.000000; 1.000000; 1.000000;,
       40; 1.000000; 1.000000; 1.000000; 1.000000;,
       41; 1.000000; 1.000000; 1.000000; 1.000000;,
       42; 1.000000; 1.000000; 1.000000; 1.000000;,
       43; 1.000000; 1.000000; 1.000000; 1.000000;,
       44; 1.000000; 1.000000; 1.000000; 1.000000;,
       45; 1.000000; 1.000000; 1.000000; 1.000000;,
       46; 1.000000; 1.000000; 1.000000; 1.000000;,
       47; 1.000000; 1.000000; 1.000000; 1.000000;,
       48; 1.000000; 1.000000; 1.000000; 1.000000;,
       49; 1.000000; 1.000000; 1.000000; 1.000000;,
       50; 1.000000; 1.000000; 1.000000; 1.000000;,
       51; 1.000000; 1.000000; 1.000000; 1.000000;,
       52; 1.000000; 1.000000; 1.000000; 1.000000;,
       53; 1.000000; 1.000000; 1.000000; 1.000000;,
       54; 1.000000; 1.000000; 1.000000; 1.000000;,
       55; 1.000000; 1.000000; 1.000000; 1.000000;,
       56; 1.000000; 1.000000; 1.000000; 1.000000;,
       57; 1.000000; 1.000000; 1.000000; 1.000000;,
       58; 1.000000; 1.000000; 1.000000; 1.000000;,
       59; 1.000000; 1.000000; 1.000000; 1.000000;,
       60; 1.000000; 1.000000; 1.000000; 1.000000;,
       61; 1.000000; 1.000000; 1.000000; 1.000000;,
       62; 1.000000; 1.000000; 1.000000; 1.000000;,
       63; 1.000000; 1.000000; 1.000000; 1.000000;,
       64; 1.000000; 1.000000; 1.000000; 1.000000;,
       65; 1.000000; 1.000000; 1.000000; 1.000000;,
       66; 1.000000; 1.000000; 1.000000; 1.000000;,
       67; 1.000000; 1.000000; 1.000000; 1.000000;,
       68; 1.000000; 1.000000; 1.000000; 1.000000;,
       69; 1.000000; 1.000000; 1.000000; 1.000000;,
       70; 1.000000; 1.000000; 1.000000; 1.000000;,
       71; 1.000000; 1.000000; 1.000000; 1.000000;,
       72; 1.000000; 1.000000; 1.000000; 1.000000;,
       73; 1.000000; 1.000000; 1.000000; 1.000000;,
       74; 1.000000; 1.000000; 1.000000; 1.000000;,
       75; 1.000000; 1.000000; 1.000000; 1.000000;,
       76; 1.000000; 1.000000; 1.000000; 1.000000;,
       77; 1.000000; 1.000000; 1.000000; 1.000000;,
       78; 1.000000; 1.000000; 1.000000; 1.000000;,
       79; 1.000000; 1.000000; 1.000000; 1.000000;,
       80; 1.000000; 1.000000; 1.000000; 1.000000;,
       81; 1.000000; 1.000000; 1.000000; 1.000000;,
       82; 1.000000; 1.000000; 1.000000; 1.000000;,
       83; 1.000000; 1.000000; 1.000000; 1.000000;,
       84; 1.000000; 1.000000; 1.000000; 1.000000;,
       85; 1.000000; 1.000000; 1.000000; 1.000000;,
       86; 1.000000; 1.000000; 1.000000; 1.000000;,
       87; 1.000000; 1.000000; 1.000000; 1.000000;,
       88; 1.000000; 1.000000; 1.000000; 1.000000;,
       89; 1.000000; 1.000000; 1.000000; 1.000000;,
       90; 1.000000; 1.000000; 1.000000; 1.000000;,
       91; 1.000000; 1.000000; 1.000000; 1.000000;,
       92; 1.000000; 1.000000; 1.000000; 1.000000;,
       93; 1.000000; 1.000000; 1.000000; 1.000000;,
       94; 1.000000; 1.000000; 1.000000; 1.000000;,
       95; 1.000000; 1.000000; 1.000000; 1.000000;,
       96; 1.000000; 1.000000; 1.000000; 1.000000;,
       97; 1.000000; 1.000000; 1.000000; 1.000000;,
       98; 1.000000; 1.000000; 1.000000; 1.000000;,
       99; 1.000000; 1.000000; 1.000000; 1.000000;,
       100; 1.000000; 1.000000; 1.000000; 1.000000;,
       101; 1.000000; 1.000000; 1.000000; 1.000000;,
       102; 1.000000; 1.000000; 1.000000; 1.000000;,
       103; 1.000000; 1.000000; 1.000000; 1.000000;,
       104; 1.000000; 1.000000; 1.000000; 1.000000;,
       105; 1.000000; 1.000000; 1.000000; 1.000000;,
       106; 1.000000; 1.000000; 1.000000; 1.000000;,
       107; 1.000000; 1.000000; 1.000000; 1.000000;,
       108; 1.000000; 1.000000; 1.000000; 1.000000;,
       109; 1.000000; 1.000000; 1.000000; 1.000000;,
       110; 1.000000; 1.000000; 1.000000; 1.000000;,
       111; 1.000000; 1.000000; 1.000000; 1.000000;,
       112; 1.000000; 1.000000; 1.000000; 1.000000;,
       113; 1.000000; 1.000000; 1.000000; 1.000000;,
       114; 1.000000; 1.000000; 1.000000; 1.000000;,
       115; 1.000000; 1.000000; 1.000000; 1.000000;,
       116; 1.000000; 1.000000; 1.000000; 1.000000;,
       117; 1.000000; 1.000000; 1.000000; 1.000000;,
       118; 1.000000; 1.000000; 1.000000; 1.000000;,
       119; 1.000000; 1.000000; 1.000000; 1.000000;,
       120; 1.000000; 1.000000; 1.000000; 1.000000;,
       121; 1.000000; 1.000000; 1.000000; 1.000000;,
       122; 1.000000; 1.000000; 1.000000; 1.000000;,
       123; 1.000000; 1.000000; 1.000000; 1.000000;,
       124; 1.000000; 1.000000; 1.000000; 1.000000;,
       125; 1.000000; 1.000000; 1.000000; 1.000000;,
       126; 1.000000; 1.000000; 1.000000; 1.000000;,
       127; 1.000000; 1.000000; 1.000000; 1.000000;;
      }

      MeshMaterialList {
       2;
       72;
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1,
       1;

       Material m_airpipes {
        0.588000; 0.588000; 0.588000; 1.000000;;
        128.000000;
        0.000000; 0.000000; 0.000000;;
        0.000000; 0.000000; 0.000000;;

        TextureFilename {
         "T_Algues_D.tga";
        }
       }

       Material m_airpipes_rim {
        0.588000; 0.588000; 0.588000; 1.000000;;
        128.000000;
        0.000000; 0.000000; 0.000000;;
        0.000000; 0.000000; 0.000000;;

        TextureFilename {
         "T_Algues_D.tga";
        }
       }

      }

      XSkinMeshHeader {
       1;
       1;
       1;
      }

      SkinWeights {
       "st_airpipe_x1";
       128;
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       8,
       9,
       10,
       11,
       12,
       13,
       14,
       15,
       16,
       17,
       18,
       19,
       20,
       21,
       22,
       23,
       24,
       25,
       26,
       27,
       28,
       29,
       30,
       31,
       32,
       33,
       34,
       35,
       36,
       37,
       38,
       39,
       40,
       41,
       42,
       43,
       44,
       45,
       46,
       47,
       48,
       49,
       50,
       51,
       52,
       53,
       54,
       55,
       56,
       57,
       58,
       59,
       60,
       61,
       62,
       63,
       64,
       65,
       66,
       67,
       68,
       69,
       70,
       71,
       72,
       73,
       74,
       75,
       76,
       77,
       78,
       79,
       80,
       81,
       82,
       83,
       84,
       85,
       86,
       87,
       88,
       89,
       90,
       91,
       92,
       93,
       94,
       95,
       96,
       97,
       98,
       99,
       100,
       101,
       102,
       103,
       104,
       105,
       106,
       107,
       108,
       109,
       110,
       111,
       112,
       113,
       114,
       115,
       116,
       117,
       118,
       119,
       120,
       121,
       122,
       123,
       124,
       125,
       126,
       127;
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000,
       1.000000;
          1.000000, -0.000000, -0.000000, 0.000000,
          -0.000000, -0.000000, 1.000000, 0.000000,
          0.000000, -1.000000, -0.000000, 0.000000,
          -0.000000, 0.000000, -0.000000, 1.000000;;
      }


     }
   }

// Start of Animation

AnimationSet Take_001 {
   Animation {
      {st_airpipe_x1}

      AnimationKey {
       2;
       1;
       0; 3; 0.000000, 0.000000, 0.000000;;;
      }

      AnimationOptions {
       0;
       1;
      }
      AnimationKey {
       1;
       1;
       0; 3; 1.000000, 1.000000, 1.000000;;;
      }

      AnimationOptions {
       0;
       1;
      }
      AnimationKey {
       0;
       1;
       0; 4; 0.707107, 0.707107, -0.000000, -0.000000;;;
      }

      AnimationOptions {
       0;
       1;
      }

   }

}
