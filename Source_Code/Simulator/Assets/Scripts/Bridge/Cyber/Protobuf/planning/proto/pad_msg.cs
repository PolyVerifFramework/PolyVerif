// This file was generated by a tool; you should avoid making direct changes.
// Consider using 'partial classes' to extend these types
// Input: pad_msg.proto

#pragma warning disable 0612, 1591, 3021
namespace apollo.planning
{

    [global::ProtoBuf.ProtoContract()]
    public partial class PadMessage : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public PadMessage()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public global::apollo.common.Header header { get; set; }

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue(DrivingAction.Follow)]
        public DrivingAction action
        {
            get { return __pbn__action ?? DrivingAction.Follow; }
            set { __pbn__action = value; }
        }
        public bool ShouldSerializeaction()
        {
            return __pbn__action != null;
        }
        public void Resetaction()
        {
            __pbn__action = null;
        }
        private DrivingAction? __pbn__action;

    }

    [global::ProtoBuf.ProtoContract()]
    public enum DrivingAction
    {
        [global::ProtoBuf.ProtoEnum(Name = @"FOLLOW")]
        Follow = 0,
        [global::ProtoBuf.ProtoEnum(Name = @"CHANGE_LEFT")]
        ChangeLeft = 1,
        [global::ProtoBuf.ProtoEnum(Name = @"CHANGE_RIGHT")]
        ChangeRight = 2,
        [global::ProtoBuf.ProtoEnum(Name = @"PULL_OVER")]
        PullOver = 3,
        [global::ProtoBuf.ProtoEnum(Name = @"STOP")]
        Stop = 4,
    }

}

#pragma warning restore 0612, 1591, 3021
