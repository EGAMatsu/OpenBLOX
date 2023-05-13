Shader "Custom/Gouraud"
{
    Properties{
        _Color("Diffuse Material Color", Color) = (1,1,1,1)
        _SpecColor("Specular Material Color", Color) = (1,1,1,1)
        _Shininess("Shininess", Float) = 10
        _MainTex("Texture", 2D) = "" {}
    }
    SubShader{
        Pass {
            Tags { "LightMode" = "ForwardBase" }
                // pass for ambient light and first light source

            CGPROGRAM

            #pragma vertex vert  
            #pragma fragment frag 

            #include "UnityCG.cginc"
            uniform float4 _LightColor0;
        // color of light source (from "Lighting.cginc")

        // User-specified properties
        uniform float4 _Color;
        uniform float4 _SpecColor;
        uniform float _Shininess;

        struct vertexInput {
        float4 vertex : POSITION;
        float3 normal : NORMAL;
        };
        struct vertexOutput {
        float4 pos : SV_POSITION;
        float4 col : COLOR;
        };

    vertexOutput vert(vertexInput input)
    {
        vertexOutput output;

        float4x4 modelMatrix = unity_ObjectToWorld;
        float3x3 modelMatrixInverse = unity_WorldToObject;
        float3 normalDirection = normalize(
            mul(input.normal, modelMatrixInverse));
        float3 viewDirection = normalize(_WorldSpaceCameraPos
            - mul(modelMatrix, input.vertex).xyz);
        float3 lightDirection;
        float attenuation;

        if (0.0 == _WorldSpaceLightPos0.w) // directional light?
        {
            attenuation = 1.0; // no attenuation
            lightDirection = normalize(_WorldSpaceLightPos0.xyz);
        }
        else // point or spot light
        {
            float3 vertexToLightSource = _WorldSpaceLightPos0.xyz
                - mul(modelMatrix, input.vertex).xyz;
            float distance = length(vertexToLightSource);
            attenuation = 1.0 / distance; // linear attenuation 
            lightDirection = normalize(vertexToLightSource);
        }

        float3 ambientLighting =
            UNITY_LIGHTMODEL_AMBIENT.rgb * _Color.rgb;

        float3 diffuseReflection =
            min(1.0f * max(0, dot(normalDirection, lightDirection) + 0.3f),0.7f) * _LightColor0.rgb * _Color.rgb;

        float3 specularReflection;
        if (dot(normalDirection, lightDirection) < 0.0)
            // light source on the wrong side?
            {
            specularReflection = float3(0.0, 0.0, 0.0);
            // no specular reflection
        }
        else // light source on the right side
        {
            specularReflection = attenuation * _LightColor0.rgb
            * _SpecColor.rgb * pow(max(0.0, dot(
            reflect(-lightDirection, normalDirection),
            viewDirection)), _Shininess);
        }

        output.col = float4(ambientLighting + diffuseReflection
            + specularReflection, 1.0);
        output.pos = UnityObjectToClipPos(input.vertex);
        return output;
    }

    float4 frag(vertexOutput input) : COLOR
    {
    return input.col;
    }

    ENDCG
    }

    Pass {
        Tags { "LightMode" = "ForwardAdd" }
        // pass for additional light sources
        Blend One One // additive blending 

        CGPROGRAM

        #pragma vertex vert  
        #pragma fragment frag 

        #include "UnityCG.cginc"
        uniform float4 _LightColor0;
        // color of light source (from "Lighting.cginc")

        // User-specified properties
        uniform float4 _Color;
        uniform float4 _SpecColor;
        uniform float _Shininess;

        struct vertexInput {
        float4 vertex : POSITION;
        float3 normal : NORMAL;
        };
        struct vertexOutput {
        float4 pos : SV_POSITION;
        float4 col : COLOR;
        };

        vertexOutput vert(vertexInput input)
        {
        vertexOutput output;

        float4x4 modelMatrix = unity_ObjectToWorld;
        float3x3 modelMatrixInverse = unity_WorldToObject;
        float3 normalDirection = normalize(
            mul(input.normal, modelMatrixInverse));
        float3 viewDirection = normalize(_WorldSpaceCameraPos
            - mul(modelMatrix, input.vertex).xyz);
        float3 lightDirection;
        float attenuation;

        if (0.0 == _WorldSpaceLightPos0.w) // directional light?
        {
            attenuation = 1.0; // no attenuation
            lightDirection = normalize(_WorldSpaceLightPos0.xyz);
        }
        else // point or spot light
        {
            float3 vertexToLightSource = _WorldSpaceLightPos0.xyz
                - mul(modelMatrix, input.vertex).xyz;
            float distance = length(vertexToLightSource);
            attenuation = 1.0 / distance; // linear attenuation 
            lightDirection = normalize(vertexToLightSource);
        }

        float3 diffuseReflection =
            attenuation * _LightColor0.rgb * _Color.rgb
            * max(0.0, dot(normalDirection, lightDirection));

        float3 specularReflection;
        if (dot(normalDirection, lightDirection) < 0.0)
            // light source on the wrong side?
        {
            specularReflection = float3(0.0, 0.0, 0.0);
            // no specular reflection
        }
        else // light source on the right side
        {
        specularReflection = attenuation * _LightColor0.rgb
            * _SpecColor.rgb * pow(max(0, dot(
            reflect(-lightDirection, normalDirection),
            viewDirection)), _Shininess);
        }

        output.col = float4(diffuseReflection
        + specularReflection, 1.0);
        // no ambient contribution in this pass
        output.pos = UnityObjectToClipPos(input.vertex);
        return output;
        }

        float4 frag(vertexOutput input) : COLOR
        {
        return input.col;
        }

        ENDCG
        }
    }

    Fallback "Specular"
}
