// This file was generated by a tool; you should avoid making direct changes.
// Consider using 'partial classes' to extend these types
// Input: config.proto

#pragma warning disable 0612, 1591, 3021
namespace apollo.image_decompress
{

    [global::ProtoBuf.ProtoContract()]
    public partial class Config : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public Config()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue("")]
        public string channel_name
        {
            get { return __pbn__channel_name ?? ""; }
            set { __pbn__channel_name = value; }
        }
        public bool ShouldSerializechannel_name()
        {
            return __pbn__channel_name != null;
        }
        public void Resetchannel_name()
        {
            __pbn__channel_name = null;
        }
        private string __pbn__channel_name;

    }

}

#pragma warning restore 0612, 1591, 3021
